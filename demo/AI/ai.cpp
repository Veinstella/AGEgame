#include "../AI/ai.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "../include/age_layer.h"
#include "../include/age_scene.h"
#include <qdebug.h>
#include "game.h"
#define MAX_X 1080
#define MAX_Y 1920


Ai::Ai(ATexture *ai_texture,int stayTime,int width,int height,int shotMods)
{
    InIt();
    this->bindTexture(ai_texture);
    this->setPos(AVector2D(0,0));
    this->setWidth(width);
    this->setHeight(height);
    this->fire_cd= new AAccumulator(0,3,0.01,false);
    this->stayTime = new AAccumulator(0,stayTime,0.01,false);
    this->stime = stayTime;
    this->width = width;
    this->height = height;
    this->shotMods = shotMods;
//    this->num = AiNum;
}

int Ai::getRand(int s)
{
    srand((unsigned) time(NULL));
    return rand() % s;
}

void Ai::AiIn(float x,float y)
{
    this->inX = x;
    this->inY = y;
}

void Ai::AiOut(float x,float y)
{
    this->outX = x;
    this->outY = y;
}

void Ai::AiStay()
{
    this->stayX = getRand(MAX_X);
    this->stayY = getRand(MAX_Y);
}

void Ai::action()
{
    AScene * game_scene=Game::single ()->getCurrent_scence();
    if(num == 0)
    {
        this->destroy();
    }

    if(this->inX > this->stayX)
    {
        this->setX((float)this->inX - 1);
        this->inX--;
    }
    if(this->inX < this->stayX)
    {
        this->setX((float)this->inX + 1);
        this->inX++;
    }
    if(this->inY > this->stayY)
    {
        this->setY((float)this->inY - 1);
        this->inY--;
    }
    if(this->inY < this->stayY)
    {
        this->setY((float)this->inY + 1);
        this->inY++;
    }
    if(this->inX == this->stayX && this->inY == this->stayY)
    {
        this->inX = this->stayX;
        this->inY = this->stayY;
        this->setY((float)this->inY);
        this->setX((float)this->inX);
        stayTime->step(ASystem::TimeStep());
    }
    if(stayTime->isTouched())
    {
        this->stayX = this->outX;
        this->stayY = this->outY;
    }
    if(this->inX == this->outX && this->inY == this->outY)
    {
        this->destroy();
    }
    if(shotMods == 1 && this->inX == this->stayX && this->inY == this->stayY)
    {
        //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15-200),200,200,-90,0.5,Game::single()->getBullet_texture()));

    }
    if(shotMods == 0)
    {
        //game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15-200),200,200,-90,0.5,Game::single()->getBullet_texture()));
    }
}

