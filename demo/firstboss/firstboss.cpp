#include "firstboss/firstboss.h"
#include "game.h"
#include <bullet/bullet.h>
#include <firstchapter/firstchapter.h>
#include <QDebug>
ACircle *FirstBoss::firstboss_circle;

FirstBoss::FirstBoss(ATexture *firstboss_texture)
{
    this->setPos(AVector2D(450,1500));
    this->bindTexture(firstboss_texture);
    this->setWidth(160);
    this->setHeight(120);
    this->fire_cd1=new AAccumulator(0,0,0,false);
    this->fire_cd2=new AAccumulator(0,3,1,false);
    this->fire_cd3=new AAccumulator(0,40,1,false);
    this->speed_x=0.07;
    this->go_left=true;
    this->go_right=false;
    this->step1=false;
    this->step2=false;
    this->step3=false;
    this->is_destory=false;
    this->angle=0;

    this->firstboss_circle=new ACircle();
    this->firstboss_circle->setCentre(this->middle());
    this->firstboss_circle->setRadius(100);
}

void FirstBoss::action()
{
    this->firstboss_circle->setCentre(this->middle());
    AScene *game_scene = Game::single()->getCurrent_scence();
    if(step1==true && step2==false)
    {
        if(count%100>=5&&count%100<=35)
        {
            fire_cd1->step(0.015*ASystem::TimeStep());
            if(fire_cd1->isTouched())
            {
                fire_cd1->rewind();
                for(angle=-140;angle<=140;angle+=70)
                {
                     Bullet *temp =new Bullet(2,AVector2D(this->getX()+this->width()/2,this->getY()+this->height()/2),AVector2D(this->hero_pos.x()+angle,this->hero_pos.y()),25,25,0,0.85,Game::single()->getBullet_boss_p1());
                    temp->setColor(0,50,256);
                    game_scene->layer(3)->addChild(temp);
                }
            }
        }
        count++;
    }
    if(step2==true)
    {
        fire_cd2->step(0.0075*ASystem::TimeStep());
        if(fire_cd2->isTouched())
        {
            fire_cd2->rewind();
            for(angle=0;angle<=360;angle+=11.5)
            {
                Bullet *temp =new Bullet(1,AVector2D(this->getX()+this->width()/2,this->getY()+this->height()/2),AVector2D(this->hero_pos.x(),this->hero_pos.y()),120,120,angle,0.5,Game::single()->getBullet_boss_p2());
                temp->setColor(256,100,0);
                game_scene->layer(3)->addChild(temp);;
            }

        }
        if(this->getX()>100 && go_left == true)
        {
            this->setX(this->getX()-speed_x*ASystem::TimeStep());
            if(this->getX()<=100)
            {
                go_left=false;
                go_right=true;
            }
        }
        if(this->getX()<980-this->width() && go_right==true)
        {
            this->setX(this->getX()+speed_x*ASystem::TimeStep()); 
            if(this->getX()>=980-this->width())
            {
                go_left=true;
                go_right=false;
            }
        }
        if(step3==true)
        {
            fire_cd3->step(0.015*ASystem::TimeStep());
            if(fire_cd3->isTouched())
            {
                fire_cd3->rewind();
                Bullet *temp =new Bullet(2,AVector2D(this->getX()+this->width()/2,this->getY()+this->height()/2),AVector2D(this->hero_pos.x(),this->hero_pos.y()),350,350,0,1,Game::single()->getBullet_boss_p3());
                //temp->setColor(256,100,0);
                game_scene->layer(3)->addChild(temp);
            }
        }
    }
}

bool FirstBoss::is_in_the_boundary_x(double x)
{
    if(x >=0 && x<=ASystem::GetWidth ()-this->width ())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FirstBoss::is_in_the_boundary_y(double y)
{
    if(y>=0&&y<=ASystem::GetHeight()-this->height())
    {
       return true;
    }
    else
    {
       return false;
    }
}
ACircle *FirstBoss::getFirstboss_circle()
{
    return firstboss_circle;
}

void FirstBoss::setFirstboss_circle(ACircle *value)
{
    firstboss_circle = value;
}


bool FirstBoss::getIs_destory() const
{
    return is_destory;
}

void FirstBoss::setIs_destory(bool value)
{
    is_destory = value;
}

AVector2D FirstBoss::getHero_pos() const
{
    return hero_pos;
}

void FirstBoss::setHero_pos(AVector2D value)
{
    hero_pos = value;
}

bool FirstBoss::getStep3() const
{
    return step3;
}

void FirstBoss::setStep3(bool value)
{
    step3 = value;
}

bool FirstBoss::getStep1() const
{
    return step1;
}

void FirstBoss::setStep1(bool value)
{
    step1 = value;
}

bool FirstBoss::getStep2() const
{
    return step2;
}

void FirstBoss::setStep2(bool value)
{
    step2 = value;
}

