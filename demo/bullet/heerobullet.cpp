#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "firstchapter/firstchapter.h"
#include "hero/hero.h"
#include "qdebug.h"
#include "game.h"
#include "bullet/heerobullet.h"

HeeroBullet::HeeroBullet(int mods,AVector2D pos,AVector2D hero_pos,double width,double height,double angle,double speed,ATexture *HeeroBullet_texture)
{
    this->bindTexture (HeeroBullet_texture);
    this->speed=speed;
    this->setWidth(width);
    this->setHeight(height);
    this->setX (pos.x ()-width/2);
    this->setY (pos.y ()-height/2);
    if(mods==1)
    {
        this->angle=angle;
        increase_x=cos(this->angle*3.1415926/180);
        increase_y=sin(this->angle*3.1415926/180);
    }
    if(mods==2)
    {
        double x=hero_pos.x()-pos.x();
        double y=hero_pos.y()-pos.y();
        this->angle = atan2(y,x)*180/3.1415926;
        increase_x=cos(this->angle*3.1415926/180);
        increase_y=sin(this->angle*3.1415926/180);
    }
    this->setCentre(this->middle());
    this->setRadius(this->width()/2);
}

bool HeeroBullet::out_of_the_boundary(double x,double y)
{

    if(x<-this->width() ||
       y<-this->height() ||
       x>ASystem::GetWidth ()+this->width() ||
      y>ASystem::GetHeight ()+this->height()
	   )
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*ACircle *HeeroBullet::getHeeroBullet_circle() const
{
    return HeeroBullet_circle;
}

void HeeroBullet::setHeeroBullet_circle(ACircle *value)
{
    HeeroBullet_circle = value;
}*/


void HeeroBullet::action()
{
    this->setX(this->getX()+increase_x*ASystem::TimeStep()*speed);
    this->setY(this->getY()+increase_y*ASystem::TimeStep()*speed);
    this->setCentre(this->middle());
    if(this->intersect(FirstChapter::getFirstboss()->getFirstboss_circle()))
    {
        FirstChapter::getHp()->change_hp();
        if(FirstChapter::getHp()->getGet_wight()==0)
        {
            FirstChapter::getHp()->destroy();
            Game::single()->getFirstchapter()->getFC_music()->stop();
            Game::single()->getDeathmenu()->activate();
        }
        this->destroy();
    }
    else  if(out_of_the_boundary(this->getX (),this->getY ()))
    {
        this->destroy ();
    }

}

