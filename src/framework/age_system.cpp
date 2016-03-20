#include "../include/age_system.h"
#include "../include/age_staticattribute.h"
#include "../include/age_widget.h"
#include <QVBoxLayout>
#include <QSize>
#include <QString>

#include <iostream>
#include <stdlib.h>
#include <QDir>
#include "../include/age_interface.h"
#include "../include/age_lua.h"
using namespace std;
namespace AGE2D{





QApplication * ASystem::m_application;
AWidget * ASystem::m_widget;
int ASystem::m_width;
int ASystem::m_height;
int ASystem::m_widthOffset;
int ASystem::m_heightOffset;

int ASystem::execute_mode;
bool ASystem::is_init=false;
QTextEdit * ASystem::m_lua_textEdit;
QString ASystem::m_debug_string;
int ASystem::system_id;
ASystem::ASystem()
{
}

int ASystem::Go()
{
	if(!is_init)
	{
		return -1;
	}
	return m_application->exec ();
}

void ASystem::SetSize(int width, int height )
{

	m_width=width;
	m_height=height;
	if(!is_init)
	{
		return ;
	}
    m_widget->resize(width,height);
    m_widget->updateWindow(width,height);
    //m_widget->showFullScreen();

    //qDebug()<<"dingdong"<<width<<"   "<<height;
}

int ASystem::Random(int min, int max)
{
 return (min + rand()% (max-min+1));
}

int ASystem::GetWidth()
{
	return m_width;
}

int ASystem::GetHeight()
{
	return m_height;
}

int ASystem::GetWidthOffset()
{
    return m_widthOffset;
}

int ASystem::GetHeightOffset()
{
    return m_heightOffset;
}

int ASystem::IsEngineInitialized()
{
	return is_init;
}

void ASystem::Init(int argc, char *argv[], int init_mode)
{
	m_application=new QApplication(argc,argv);
    is_init=true;
	m_widget=new AWidget();
	SetSize(640,480);
    m_widget->show();
    m_lua_textEdit = new QTextEdit();
    /*m_lua_textEdit->setWindowFlags(Qt::CustomizeWindowHint |
                                   Qt::WindowMinimizeButtonHint |
                                   Qt::WindowMaximizeButtonHint);*/
    m_lua_textEdit->hide();


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

    execute_mode=init_mode;
    switch(init_mode)
    {
        case AGE_NATIVE:

        break;
    case AGE_LUA:
        ALua::init();
        ARegisterToLua();
        ALua::SetPackagePath();
        if(argc==2)
            {
            ALua::execute(argv[1]);

        }
        else
        {
            ALua::execute("AGE2D/entry.lua");
        }
        break;
    }
}

void ASystem::ShowLuaEdit()
{
    m_lua_textEdit->show();
}

void ASystem::HideLuaEdit()
{
    m_lua_textEdit->hide();
}

void ASystem::SetLuaEditSize(int x,int y)
{
    m_lua_textEdit->resize(x,y);
}

QString ASystem::Path(const char *str)
{

    QString second(str);
    switch(system_id)
    {
        case WINDOWS:
{
    QString temp = "./AGE2D/" + second;
    return temp;
    }
        break;

    case ANDROID_BUILT_IN:
    {
    QString temp = "/storage/emulated/0/AGE2D/" + second;
    return temp;
    }
        break;

    case ANDROID_EXTERNAL_STORAGE:
    {
    QString temp = "/sdcard/AGE2D/" + second;
    return temp;
    }
        break;

    case ANDROID_MOUNT_DISK:
    {
    QString temp = "/mnt/sdcard/AGE2D/" + second;
    return temp;
    }
        break;
    }
}

QString ASystem::Path(QString str)
{

    QString second(str);
    switch(system_id)
    {
        case WINDOWS:
{
    QString temp = "./AGE2D/" + second;
    return temp;
    }
        break;

    case ANDROID_BUILT_IN:
    {
    QString temp = "/storage/emulated/0/AGE2D/" + second;
    return temp;
    }
        break;

    case ANDROID_EXTERNAL_STORAGE:
    {
    QString temp = "/sdcard/AGE2D/" + second;
    return temp;
    }
        break;

    case ANDROID_MOUNT_DISK:
    {
    QString temp = "/mnt/sdcard/AGE2D/" + second;
    return temp;
    }
        break;
    }
}

int ASystem::GetExecuteMode()
{
    return execute_mode;
}

void ASystem::AddDebugInfo(QString str)
{
    m_debug_string += str;
    m_lua_textEdit->show();
    m_lua_textEdit->setText(m_debug_string);
    m_lua_textEdit->setTextColor(QColor(255,0,0));
    qDebug()<<str;
}

int ASystem::TimeStep()
{
	return getTimeStep();
}

double ASystem::FrameRate()
{
	return 1000.0/getTimeStep ();
}

AWidget * ASystem::GetWidget()
{
    return m_widget;
}
}
