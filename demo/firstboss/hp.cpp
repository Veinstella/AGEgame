#include <firstboss/hp.h>
#include "../include/age_system.h"
#include <game.h>

Hp::Hp()
{
    bindTexture(Game::single()->getHp_texture());
    setPos(AVector2D(20,1860));
    setWidth(850);
    setHeight(10);
    this->hold_wight=200;
    this->start_wight=850;
    this->get_wight=850;
}

void Hp::action()
{
    if(this->start_wight>0)
    {
        /*start_wight-=0.007*i*ASystem::TimeStep();
        //start_wight-=0.1*i*ASystem::TimeStep();
        setWidth(start_wight);
        this->get_wight=start_wight;
        */
    }
    else
    {
        //this->destroy();
    }
}

void Hp::change_hp()
{
    start_wight-=0.007*i*ASystem::TimeStep();
    //start_wight-=0.1*i*ASystem::TimeStep();
    setWidth(start_wight);
    this->get_wight=start_wight;
}

void Hp::destroy()
{
    this->destroy();
}

float Hp::getGet_wight() const
{
    return get_wight;
}

void Hp::setGet_wight(float value)
{
    get_wight = value;
}

