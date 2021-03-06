#include <../include/age_widget.h>
#include <../include/age_staticattribute.h>
extern "C"
{
    #include "../include/age_lua.h"
}
#include <QMouseEvent>
#include <QTouchEvent>
#include <QKeyEvent>
#include <list>
#include <../include/age_mouseinfo.h>
//#include <iostream>
#include <QElapsedTimer>
#include <QFont>
#include <QDebug>
#include "../include/age_texture.h"
using namespace std;

namespace AGE2D
{
AWidget::AWidget(QWidget *)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer))
{
    //setFixedSize(640,480);
    scale_factor=1;
    screen_offset_x=0;
    screen_offset_y=0;
    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    //m_luaEdit->hide();
}

AWidget::~AWidget()
{

}

void AWidget::initializeGL()
{
    setCurrentScene(NULL);
    initializeGLFunctions();

    qglClearColor(Qt::black);

    //glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initDefalutShaderProgram();
    initResources();
    m_timer.start(15, this);
}

void AWidget::resizeGL(int w, int h)
{
    updateWindow(w,h);
}

void AWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //setViewPortMatrix(projection);
    display();
}

void AWidget::timerEvent(QTimerEvent *)
{
    QElapsedTimer timer;
    timer.start();
    updateGL();
    setTimeStep(timer.elapsed()+15);
}

void AWidget::display()
{
    if(ASystem::GetExecuteMode()==AGE_LUA)
    {
        //lua function
        lua_State * lua=ALua::getLua();
        if(ALua::is_execute())
        {
            lua_getglobal(lua,"__on_render"); /* 这里接收不到lua里的函数*/
            lua_pcall(lua, 0, 1, 0);
            lua_pop(lua, 1);
        }
        else
        {
        }
    }
    else
    {


        if(getCurrentScene())
        {
            getCurrentScene()->renderScene(is_release,is_press,mouse_pos);
        }
    }
    is_release=false;
    is_press=false;

}

void AWidget::initResources()
{
    is_release=false;
    is_press=false;
    mouse_pos=AVector2D(0,0);
}

void AWidget::mouseMoveEvent(QMouseEvent * mouse)
{
    this->setMouseTracking(true);
    int mouse_x=0;
    int mouse_y=0;
    mouse_x=(mouse->x()-ASystem::GetWidget()->getScreenOffsetX())/ASystem::GetWidget()->getScaleFactor();
    mouse_y=((ASystem::GetWidget()->getReal_height()-mouse->y())-ASystem::GetWidget()->getScreenOffsetY())/ASystem::GetWidget()->getScaleFactor();
    if(mouse_x<0 || mouse_x>ASystem::GetWidth() || mouse_y<0 || mouse_y>ASystem::GetHeight())
    {
    }
    else
    {
        if(ASystem::GetExecuteMode()==AGE_LUA)
        {
            lua_State * lua=ALua::getLua();
            if(ALua::is_execute())
            {
                lua_getglobal(lua,"__on_touch_move"); /* 这里接收不到lua里的函数*/
                lua_pushnumber(lua,mouse_x);
                lua_pushnumber(lua,mouse_y);
                lua_pcall(lua, 2, 1, 0);
                lua_pop(lua, 1);
            }
            else
            {
            }
        }
        else
        {
            if(getCurrentScene())
            {
                AEventMgr * mgr=getCurrentScene()->eventMgr();
                mgr->mouseMoveEvent(mouse);
            }
        }

    }
}

void AWidget::mousePressEvent(QMouseEvent *mouse)
{
    int mouse_x=0;
    int mouse_y=0;
    mouse_x=(mouse->x()-ASystem::GetWidget()->getScreenOffsetX())/ASystem::GetWidget()->getScaleFactor();
    mouse_y=((ASystem::GetWidget()->getReal_height()-mouse->y())-ASystem::GetWidget()->getScreenOffsetY())/ASystem::GetWidget()->getScaleFactor();
    if(mouse_x<0 || mouse_x>ASystem::GetWidth() || mouse_y<0 || mouse_y>ASystem::GetHeight())
    {
    }
    else
    {
        is_press =true;
        mouse_pos=AVector2D(mouse_x,mouse_y);

        if(ASystem::GetExecuteMode()==AGE_LUA)
        {
            lua_State * lua=ALua::getLua();
            if(ALua::is_execute())
            {
                lua_getglobal(lua,"__on_touch_press"); //这里接收不到lua里的函数
                lua_pushnumber(lua,mouse_x);
                lua_pushnumber(lua,mouse_y);
                lua_pcall(lua, 2, 1, 0);
                lua_pop(lua, 1);
            }
            else
            {
            }
        }
        else
        {
            if(getCurrentScene())
            {
                AEventMgr * mgr=getCurrentScene()->eventMgr();
                mgr->mousePressEvent(mouse);
            }
        }

    }
}

void AWidget::mouseReleaseEvent(QMouseEvent *mouse)
{
    int mouse_x=0;
    int mouse_y=0;
    mouse_x=(mouse->x()-ASystem::GetWidget()->getScreenOffsetX())/ASystem::GetWidget()->getScaleFactor();
    mouse_y=((ASystem::GetWidget()->getReal_height()-mouse->y())-ASystem::GetWidget()->getScreenOffsetY())/ASystem::GetWidget()->getScaleFactor();
    if(mouse_x<0 || mouse_x>ASystem::GetWidth() || mouse_y<0 || mouse_y>ASystem::GetHeight())
    {
    }
    else
    {

        is_release =true;
        mouse_pos=AVector2D(mouse_x,mouse_y);

        if(ASystem::GetExecuteMode()==AGE_LUA)
        {
            lua_State * lua=ALua::getLua();
            if(ALua::is_execute())
            {
                lua_getglobal(lua,"__on_touch_release"); /* 这里接收不到lua里的函数*/
                lua_pushnumber(lua,mouse_x);
                lua_pushnumber(lua,mouse_y);
                lua_pcall(lua, 2, 1, 0);
                lua_pop(lua, 1);
            }
            else
            {
            }
        }        else
        {
            if(getCurrentScene())
            {
                AEventMgr * mgr=getCurrentScene()->eventMgr();
                mgr->mouseReleaseEvent(mouse);
            }
        }
    }
}





void AWidget::mouseDoubleClickEvent(QMouseEvent *mouse)
{
    setCurrentMouseEvent(mouse);

}

void AWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(ASystem::GetExecuteMode()==AGE_LUA)
    {
        lua_State * lua=ALua::getLua();
        if(ALua::is_execute())
        {
            lua_getglobal(lua,"__on_key_release"); /* 这里接收不到lua里的函数*/
            lua_pushnumber(lua,event->key());
            lua_pcall(lua, 1, 1, 0);
            lua_pop(lua, 1);
        }
        else
        {
        }
    }
    else
    {
        if(getCurrentScene())
        {
            AEventMgr * mgr=getCurrentScene()->eventMgr();
            mgr->keyReleaseEvent(event);
        }
    }

}

void AWidget::keyPressEvent(QKeyEvent *event)
{
    if(ASystem::GetExecuteMode()==AGE_LUA)
    {
        lua_State * lua=ALua::getLua();
        if(ALua::is_execute())
        {
            lua_getglobal(lua,"__on_key_press"); /* 这里接收不到lua里的函数*/
            lua_pushnumber(lua,event->key());
            lua_pcall(lua, 1, 1, 0);
            lua_pop(lua, 1);
        }
        else
        {
        }
    }else
    {

            if(getCurrentScene())
            {
                AEventMgr * mgr=getCurrentScene()->eventMgr();
                mgr->keyPressEvent(event);
            }

    }


}
int AWidget::getReal_height() const
{
    return real_height;
}

void AWidget::setReal_height(int value)
{
    real_height = value;
}

void AWidget::updateWindow(int w, int h)
{
    int width = ASystem::GetWidth();
    int height = ASystem::GetHeight();
    screen_offset_x=0;
    screen_offset_y=0;
    scale_factor=w*1.0/ASystem::GetWidth();
    if(ASystem::GetHeight()*scale_factor>h)
    {
        scale_factor=h*1.0/ASystem::GetHeight();
    }
    screen_offset_x=(w-ASystem::GetWidth()*scale_factor)/2;
    screen_offset_y=(h-ASystem::GetHeight()*scale_factor)/2;
          int wi = ASystem::GetWidth()*scale_factor, he = ASystem::GetHeight()*scale_factor;
          glViewport(screen_offset_x,screen_offset_y,wi,he);
    real_width=w;
    real_height=h;
    projection.setToIdentity();
    projection.frustum (0,ASystem::GetWidth(),0,ASystem::GetHeight(),0.01,50);

    ASystem::m_widthOffset = w-wi;
    ASystem::m_heightOffset = h-he;
    setViewPortMatrix(projection);
}

int AWidget::getReal_width() const
{
    return real_width;
}

void AWidget::setReal_width(int value)
{
    real_width = value;
}

int AWidget::getScreenOffsetY() const
{
    return screen_offset_y;
}

void AWidget::setScreenOffsetY(int value)
{
    screen_offset_y = value;
}

int AWidget::getScreenOffsetX() const
{
    return screen_offset_x;
}

void AWidget::setScreenOffsetX(int value)
{
    screen_offset_x = value;
}

double AWidget::getScaleFactor() const
{
    return scale_factor;
}

void AWidget::setScaleFactor(double value)
{
    scale_factor = value;
}

}

