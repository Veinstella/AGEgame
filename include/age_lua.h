#ifndef AGE_LUA_H
#define AGE_LUA_H

#include <QString>
#include "../include/age_system.h"
extern "C" {
#include <../lua_src/lua.h>
#include <../lua_src/lualib.h>
#include <../lua_src/lauxlib.h>
}

#define AGE_LUA_DEBUG(a) if(a){const char* error = lua_tostring(ALua::getLua(), -1);qDebug()<<"error:"<<error;qDebug()<<"debug-complate";}
#define AGE_LUA_DEBUG_2(a) ALua::printDebugError(ALua::getLua(),a);
#define AGE_LUA_ADD_DEBUGEDIT(a) ALua::addDebugInfo("-----------\n");\
    ALua::addDebugInfo(QString("error arguments to function '")+QString(a)+QString("\n"));\
    ALua::addDebugInfo("-----------\n");;
namespace AGE2D {


class ALua
{
public:
  static void init();
  static void execute(const char * string);
  static void close();
  static lua_State * getLua();
  static bool is_execute();
  static int getSystemID();
  static void printDebugError(lua_State* L,int sErr);
  static void addDebugInfo(QString str);
  static void addStdout(QString str);
  static void SetPackagePath();
private:
    ALua();
   static QString m_lua_stdout;
   static lua_State *L;
};


}


#endif // AGE_LUA_H
