#include "../include/age_lua.h"
#include <QDebug>
#include <QDir>
#include <QString>
#include <../include/age_system.h>
#include <ostream>
#include <istream>

namespace AGE2D {
lua_State *ALua::L;
static bool m_isExecute = false;
static SystemID system_id;
QString ALua::m_lua_stdout;

void ALua::init()
{
    L = luaL_newstate();
    luaL_openlibs(L);
        if(QDir("C:/Windows").exists())
        {
            system_id = WINDOWS;
        }
        else
            if(QDir("/storage/emulated/0").exists())
            {
                system_id = ANDROID_BUILT_IN ;
            }
            else
                if(QDir("/sdcard").exists())
                {
                    system_id = ANDROID_EXTERNAL_STORAGE;
                }
            else if(QDir("/mnt/sdcard").exists())
                {
                    system_id = ANDROID_MOUNT_DISK;
                }
}

bool ALua::is_execute()
{
    return m_isExecute;
}

void ALua::execute(const char *string)
{
    QString second(string);

    if(QDir("C:/Windows").exists())
    {
        qDebug()<<"windows system";

        QString temp = "./" + second;
        system_id = WINDOWS;
        AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
    }
    else
        if(QDir("/storage/emulated/0").exists())
        {
            qDebug()<<"android system | build-in  storage";
            QString temp = "/storage/emulated/0/" + second;
            system_id = ANDROID_BUILT_IN ;
            AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
        }
        else
            if(QDir("/sdcard").exists())
            {
                qDebug()<<"android system | External storage";
                QString temp = "/sdcard/" + second;
                system_id = ANDROID_EXTERNAL_STORAGE;
                AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
            }
        else if(QDir("/mnt/sdcard").exists())
            {
                qDebug()<<"android system | mount disk";
                QString temp = "/mnt/sdcard/" + second;
                system_id = ANDROID_MOUNT_DISK;
                AGE_LUA_DEBUG_2(luaL_dofile(L,temp.toStdString().data()));
            }
    else
            {
            AGE_LUA_DEBUG_2(luaL_dofile(L,string));
            }
    m_isExecute = true;
}

void ALua::printDebugError(lua_State* L,int sErr)
{
    if(sErr == 0)
    {
        return;
    }

    const char* error;
      switch(sErr)
      {
      case LUA_ERRSYNTAX://编译时错误
          /*const char *buf = "mylib.myfun()2222";类似这行语句可以引起编译时错误*/
          //qDebug()<<"------syntax error during pre-compilation------";
          addDebugInfo(QString("------syntax error during pre-compilation------"));
          break;
      case LUA_ERRMEM://内存错误
          //qDebug()<<"------memory allocation error------";
          addDebugInfo(QString("------memory allocation error------"));
          break;
      case LUA_ERRRUN://运行时错误
          //qDebug()<<"------a runtime error------";
          addDebugInfo(QString("------a runtime error------"));
          break;
      case LUA_YIELD://线程被挂起错误
          //qDebug()<<"------Thread has Suspended------";
          addDebugInfo(QString("------Thread has Suspended------"));
          break;
      case LUA_ERRERR://在进行错误处理时发生错误
          //qDebug()<<"------error while running the error handler function-------";
          addDebugInfo(QString("------error while running the error handler function-------"));
          break;
      default:
          break;
      }
      error = lua_tostring(L, -1);//打印错误结果
      addDebugInfo(QString(error));
      //qDebug()<<"--------End--------";
      addDebugInfo(QString("--------End--------"));
}

void ALua::close()
{
    lua_close(L);
}

void ALua::addDebugInfo(QString str)
{
    ASystem::AddDebugInfo(str);
}

void ALua::addStdout(QString str)
{
    m_lua_stdout += str;
}

void ALua::SetPackagePath()
{
    lua_getglobal( L, "package" );
        lua_getfield( L, -1, "path" ); // get field "path" from table at top of stack (-1)
        std::string cur_path = lua_tostring( L, -1 ); // grab path string from top of stack
        cur_path.append( ";" ); // do your path magic here
        char * path=NULL;
        switch(ALua::getSystemID())
        {
            case WINDOWS:
            path="./AGE2D/libs/?.lua";
            break;
        case ANDROID_BUILT_IN:
            path="/storage/emulated/0/AGE2D/libs/?.lua";
            break;
        case ANDROID_EXTERNAL_STORAGE:
            path="/sdcard/AGE2D/libs/?.lua";
            break;
        case ANDROID_MOUNT_DISK:
            path="/mnt/sdcard/AGE2D/libs/?.lua";
            break;
        }
        cur_path.append( path );
        lua_pop( L, 1 ); // get rid of the string on the stack we just pushed on line 5
        lua_pushstring( L, cur_path.c_str() ); // push the new one
        lua_setfield( L, -2, "path" ); // set the field "path" in table at -2 with value at top of stack
        lua_pop( L, 1 ); // get rid of package table from top of stack
}

int ALua::getSystemID()
{
    return system_id;
}

lua_State *ALua::getLua()
{
    return L;
}

ALua::ALua()
{


}
}
