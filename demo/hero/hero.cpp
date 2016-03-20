#include "../hero/hero.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "../include/age_layer.h"
#include "../include/age_scene.h"
#include "game.h"
#include <QDebug>
#define speed 0.6
ACircle *Hero::hero_circle;

Hero::Hero(ATexture *hero_texture)
{
    this->setPos(AVector2D(200,200));
    this->bindTexture(hero_texture);
    this->animationset= new AAnimationSet(ASystem::Path("config/xml/hero.xml"));
    this->bindAnimationSet(this->animationset);
    this->turn_left=false;
    this->turn_right=false;
    this->fore_ward=false;
    this->back_ward=false;
    this->is_firing=true;
    this->put_mouse=false;
    this->sneak=false;
    this->fire_cd= new AAccumulator(0,4,0.02,false);
    this->frame_static= new AAccumulator(0,6,1,false);
    this->frame_left= new AAccumulator(0,4,1,false);
    this->frame_right= new AAccumulator(0,4,1,false);
    this->bullet_music = new AAudio(ASystem::Path("resource/music/bullet.wav"));
    this->bullet_music->setVolume(30);
    this->bullet_music->setLoopORnot(true);
    this->hero_particle= new ParticleLauncher(ASystem::Path("config/particle_ini/hero.ini").toStdString().c_str(),5);
    //在这里加载子弹的音乐，跟原来的audio用法一样，然后在后面的子弹设计的action里面play
    this->trymusic = new ASound(ASystem::Path("resource/music/bullet.wav"));
    this->trymusic->setVolume(0.1);


    this->hero_circle= new ACircle();
    this->hero_circle->setCentre(this->middleX(),this->middleY()+20);
    this->hero_circle->setRadius(1);



}



void Hero::onKeyRelease(QKeyEvent *event)
{
    switch(event->key ())
    {
    case Qt::Key_Left:
        turn_left=false;
        break;
    case Qt::Key_Right:
        turn_right=false;
        break;
    case Qt::Key_Up:
        fore_ward=false;
        break;
    case Qt::Key_Down:
        back_ward=false;
        break;
    case Qt::Key_Z:
        is_firing=true;
        break;

    }
    if(event->nativeVirtualKey() == 16)
    {
        sneak=false;
    }
}

void Hero::onKeyPress(QKeyEvent *event)
{
    switch(event->key ())
    {
    case Qt::Key_Left:
        turn_left=true;
        break;
    case Qt::Key_Right:
        turn_right=true;
        break;
    case Qt::Key_Up:
        fore_ward=true;
        break;
    case Qt::Key_Down:
        back_ward=true;
        break;
    case Qt::Key_Z:
        is_firing=true;
        break;

    }
    if(event->modifiers ()==Qt::ShiftModifier)
    {
        sneak=true;
    }
}

void Hero::onMouseMove(AMouseInfo info)
{
    mousePos.setX(info.getMouseX());
    mousePos.setY(info.getMouseY());
}

void Hero::onMouseRelease(AMouseInfo info)
{
    mousePos.setX(info.getMouseX());
    mousePos.setY(info.getMouseY());
    put_mouse = false;
}

void Hero::onMousePress(AMouseInfo info)
{
    mousePos.setX(info.getMouseX());
    mousePos.setY(info.getMouseY());

    AVector2D heroPos(this->getX(),this->getY());
    length = (mousePos - heroPos).length();
    float y = this->getY() - mousePos.y() ;
    float x = this->getX() - mousePos.x();
    angle = atan2(y,x)*180/3.1415;
    qDebug()<<"angle:"<<angle;
    put_mouse = true;
}

void Hero::action()
{
    this->hero_circle->setCentre(this->middleX(),this->middleY()+20);
    AVector2D velocity(0,0);
    if(frame_static->currentValue()==frame_static->getEndValue())
        frame_static->rewind();
    frame_static->step(0.01*ASystem::TimeStep());

    this->animate("static",frame_static->currentValue(),true);
    this->setWidth(256*0.8);
    this->setHeight(256*0.8);
    if(!put_mouse)
    {
        if(turn_left==true)
        {
            velocity.setX (-1*speed*ASystem::TimeStep ());
        }
        if(turn_right==true)
        {
            velocity.setX (speed*ASystem::TimeStep ());
        }
        if(fore_ward==true)
        {
            velocity.setY (speed*ASystem::TimeStep ());
        }
        if(back_ward==true)
        {
            velocity.setY (-1*speed*ASystem::TimeStep ());
        }
    }
    else
    {
        int x = mousePos.x() + length * cos(angle*3.1415/180);
        int y = mousePos.y() + length * sin(angle*3.1415/180);
        if(is_in_the_boundary_x(x) && (x-mousePos.x())<0)
        {
            this->setX(x);
        }
        if(is_in_the_boundary_x(x) && (x-mousePos.x())>0)
        {
            this->setX(x);
        }
        if(is_in_the_boundary_y(y))
        {
            this->setY(y);
        }
    }

    if(sneak)
    {
        velocity*=0.4;
    }

    if(is_in_the_boundary_x (this->getX ()+velocity.x ()))
    {
        this->setX (this->getX ()+velocity.x ());
    }

    if(is_in_the_boundary_y(this->getY()+velocity.y()))
    {
       this->setY(this->getY()+velocity.y());
    }

    fire_cd->step (ASystem::TimeStep ()*2);

    AScene * game_scene=Game::single ()->getCurrent_scence();
    /*ParticleLauncher(game_scene->layer(1),Game::single()->getGas_texture(),2,0,AVector2D(this->getX()+15+10,this->getY()+50),
                     AVector2D(75,75),AVector2D(0,0),AColor(1,1,1),
                     AColor(1,0,1),0,100,1,0,4,AVector2D(0,-3),10);
    ParticleLauncher(game_scene->layer(1),Game::single()->getGas_texture(),2,0,AVector2D(this->getX()+115-10,this->getY()+50),
                     AVector2D(75,75),AVector2D(0,0),AColor(1,1,1),
                     AColor(1,0,1),0,100,1,0,4,AVector2D(0,-3),10);*/
    hero_particle->fire(AVector2D(this->getX()+25,this->getY()+50),game_scene->layer(1));
    hero_particle->fire(AVector2D(this->getX()+105,this->getY()+50),game_scene->layer(1));

    if(fire_cd->isTouched ())
    {
        fire_cd->rewind ();
        if(is_firing)
        {
            //this->bullet_music->stop();
            //this->bullet_music->play();
            //this->trymusic->play();
            HeeroBullet *hero_bullet0=new HeeroBullet(1,AVector2D(this->middleX(),this->middleY()+150),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture());
            game_scene->layer (2)->addChild(hero_bullet0);
            HeeroBullet *hero_bullet1=new HeeroBullet(1,AVector2D(this->middleX()-50,this->middleY()+100),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture());
            game_scene->layer (2)->addChild(hero_bullet1);
            HeeroBullet *hero_bullet2=new HeeroBullet(1,AVector2D(this->middleX()+50,this->middleY()+100),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture());
            game_scene->layer (2)->addChild(hero_bullet2);
            HeeroBullet *hero_bullet3=new HeeroBullet(1,AVector2D(this->middleX()-25,this->middleY()+50),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture());
            game_scene->layer (2)->addChild(hero_bullet3);
            HeeroBullet *hero_bullet4=new HeeroBullet(1,AVector2D(this->middleX()+25,this->middleY()+50),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture());
            game_scene->layer (2)->addChild(hero_bullet4);
            //game_scene->layer (2)->addChild (new Bullet(1,AVector2D(this->middleX()-50,this->middleY()-50),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture()));
            //game_scene->layer (2)->addChild (new Bullet(1,AVector2D(this->middleX()+50,this->middleY()-50),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture()));
            //game_scene->layer (2)->addChild (new Bullet(1,AVector2D(this->middleX()-25,this->middleY()-75),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture()));
            //game_scene->layer (2)->addChild (new Bullet(1,AVector2D(this->middleX()+25,this->middleY()-75),AVector2D(0,0),200,200,90,3,Game::single()->getBullet_texture()));

        }

     }

}

bool Hero::is_in_the_boundary_x(double x)
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

bool Hero::is_in_the_boundary_y(double y)
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
ACircle *Hero::getHero_circle()
{
    return hero_circle;
}

void Hero::setHero_circle(ACircle *value)
{
    hero_circle = value;
}


AAudio *Hero::getBullet_music() const
{
    return bullet_music;
}

void Hero::setBullet_music(AAudio *value)
{
    bullet_music = value;
}




