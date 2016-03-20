#include "firstchapter/firstchapter.h"
#include <game.h>
Hero *FirstChapter::hero;
FirstBoss *FirstChapter::firstboss;
Hp *FirstChapter::hp;

FirstChapter::FirstChapter()
{
    initResource();
    initActor();
    initData();
}

void FirstChapter::initResource()
{
    hero = new Hero(Game::single()->getHero_texture());
    FC_back_ground_texture = new BackGround(Game::single()->getBackgroundtexture_FC1());
    FC_back_ground_texture_2 = new BackGround(Game::single()->getBackgroundtexture_FC2());
    firstboss = new FirstBoss(Game::single()->getFirstboss_texture());
    hp = new Hp();
    FC_music= new AAudio(ASystem::Path("resource/music/001.mp3"));
    //collisionworld = new A_CollisionWorld();
    //collisiongroup = new ACollisionGroup();
    //circle = new ACircle();
}

void FirstChapter::initActor()
{
    FC_back_ground_texture->setIs_move_y(true);
    FC_back_ground_texture->setIs_photo_cycle(true);
    FC_back_ground_texture->setOffset_y(-1);
    FC_back_ground_texture->setSpeed(0.05);

    FC_back_ground_texture_2->setY(1920);
    FC_back_ground_texture_2->setIs_move_y(true);
    FC_back_ground_texture_2->setIs_photo_cycle(true);
    FC_back_ground_texture_2->setOffset_y(-1);
    FC_back_ground_texture_2->setSpeed(0.05);

    //collisiongroup->add(hero->getHero_circle());
    //collisiongroup->add(firstboss->getFirstboss_circle());


    FC_music->setLoopORnot(true);
    FC_music->setVolume(30);

    setListenerManager(new AEventMgr());
    eventMgr()->addMouseListener(hero);
    eventMgr()->addKeyListener(hero);
    eventMgr()->addFrameListener(FC_music);
    layer(1)->addChild(FC_back_ground_texture);
    layer(1)->addChild(FC_back_ground_texture_2);
    addLayer();
    addLayer();
    layer(2)->addChild(hero);
}

void FirstChapter::initData()
{
    i=0;
    j=0;
    count=0;
    count1=-2;
}

void FirstChapter::action()
{

    if(firstboss != NULL)
    {
        if(hero->getHero_circle()->intersect(firstboss->getFirstboss_circle()))
        {
            Game::single()->getFirstchapter()->getFC_music()->stop();
            Game::single()->getDeathmenu()->activate();
        }

        if(count==148)
        {
            layer(2)->addChild(firstboss);
            layer(2)->addChild(hp);
            this->firstboss->setStep1(true);
        }

        if(firstboss->getStep1()==true)
        {
            if(count1%50==0)
                this->firstboss->setHero_pos(AVector2D(this->hero->getX()+this->hero->width()/2,this->hero->getY()+this->hero->height()/2));
            count1++;
        }

        if(this->hp->getGet_wight()<=500)
            this->firstboss->setStep2(true);
        if(this->hp->getGet_wight()<=200)
        {
            this->firstboss->setHero_pos(AVector2D(this->hero->getX()+this->hero->width()/2,this->hero->getY()+this->hero->height()/2));
            this->firstboss->setStep3(true);
        }
        if(this->hp->getGet_wight()<=0)
            this->firstboss->setIs_destory(true);

        if(this->firstboss->is_destory == true)
        {
            this->firstboss->destroy();
            this->firstboss = NULL;
        }
        count++;
    }

}

void FirstChapter::destroy()
{
    delete this->hero;
    delete this->firstboss;
    //delete this->hp;
    delete this->FC_back_ground_texture;
    delete this->FC_back_ground_texture_2;
    delete [] this->ai;

}

void FirstChapter::onKeyPress(QKeyEvent *event)
{

}
Hp *FirstChapter::getHp()
{
    return hp;
}

void FirstChapter::setHp(Hp *value)
{
    hp = value;
}

FirstBoss *FirstChapter::getFirstboss()
{
    return firstboss;
}

void FirstChapter::setFirstboss(FirstBoss *value)
{
    firstboss = value;
}

Hero *FirstChapter::getHero()
{
    return hero;
}

void FirstChapter::setHero(Hero *value)
{
    hero = value;
}

AAudio *FirstChapter::getFC_music() const
{
    return FC_music;
}

void FirstChapter::setFC_music(AAudio *value)
{
    FC_music = value;
}

void FirstChapter::onKeyRelease(QKeyEvent *event)
{

}

void FirstChapter::onMouseMove(AMouseInfo info)
{

}

void FirstChapter::onMousePress(AMouseInfo info)
{

}

void FirstChapter::onMouseRelease(AMouseInfo info)
{

}





