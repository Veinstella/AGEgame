#include "background/background.h"
#include "game.h"

bool BackGround::getIs_move_x() const
{
    return is_move_x;
}

void BackGround::setIs_move_x(bool value)
{
    is_move_x = value;
}

bool BackGround::getIs_move_y() const
{
    return is_move_y;
}

void BackGround::setIs_move_y(bool value)
{
    is_move_y = value;
}

bool BackGround::getIs_photo_cycle() const
{
    return is_photo_cycle;
}

void BackGround::setIs_photo_cycle(bool value)
{
    is_photo_cycle = value;
}



float BackGround::getSpeed() const
{
    return speed;
}

void BackGround::setSpeed(float value)
{
    speed = value;
}

float BackGround::getOffset_x() const
{
    return offset_x;
}

void BackGround::setOffset_x(float value)
{
    offset_x = value;
}

float BackGround::getOffset_y() const
{
    return offset_y;
}

void BackGround::setOffset_y(float value)
{
    offset_y = value;
}
BackGround::BackGround(ATexture *background_texture)
{
    this->bindTexture(background_texture);
    this->speed=1;
    this->offset_x=0;
    this->offset_y=0;
    this->is_move_x=false;
    this->is_move_y=false;
    this->is_photo_cycle=false;
}

void BackGround::action()
{
    if(this->is_move_x)
        this->setX(this->getX()+this->offset_x*this->speed*ASystem::TimeStep());
    if(this->is_move_y)
        this->setY(this->getY()+this->offset_y*this->speed*ASystem::TimeStep());
    if(this->is_photo_cycle)
    {
        if(this->offset_x>0)
        {
            if(this->getX()>1080)
            {
                this->setX(-1080);
            }
        }
        else
        {
            if(this->getX()<-1080)
            {
                this->setX(1080);
            }
        }
        if(this->offset_y>0)
        {
            if(this->getY()>1920)
            {
                this->setY(-1920);
            }
        }
        else
        {
            if(this->getY()<-1920)
            {
                this->setY(1920);
            }
        }
    }
}

