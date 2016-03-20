#ifndef FIRSTCHAPTER_H
#define FIRSTCHAPTER_H
#include "../include/age_texture.h"
#include "../include/age_sprite.h"
#include "../include/age_audio.h"
#include "../include/age_font.h"
#include "../include/age_scene.h"
#include "../include/age_collisiongroup.h"
#include "../include/age_collisionworld.h"
#include "../include/ashape.h"
#include "../include/acircle.h"
#include <hero/hero.h>
#include <AI/ai.h>
#include <background/background.h>
#include <firstboss/firstboss.h>
#include <firstboss/hp.h>
using namespace AGE2D;

class FirstChapter: public AScene,public AMouseListener,public AKeyListener
{
public:
    FirstChapter();
    void destroy();

    AAudio *getFC_music() const;
    void setFC_music(AAudio *value);

    static Hero *getHero();
    static void setHero(Hero *value);

    static FirstBoss *getFirstboss();
    static void setFirstboss(FirstBoss *value);

    static Hp *getHp();
    static void setHp(Hp *value);

protected:
    void action();
    void onMouseMove(AMouseInfo info); //鼠标事件管理器
    void onMousePress(AMouseInfo info);
    void onMouseRelease(AMouseInfo info);
    void onKeyRelease(QKeyEvent * event);
    void onKeyPress (QKeyEvent *event);

private:
    static Hero *hero;
    static FirstBoss  * firstboss;
    static Hp * hp;
    BackGround * FC_back_ground_texture;
    BackGround * FC_back_ground_texture_2;

    //A_CollisionWorld * collisionworld;
    //ACollisionGroup * collisiongroup;
    //ACircle * circle;

    AAudio * FC_music;
    void initResource();
    void initActor();
    void initData();
    Ai *ai[5];
    int i,j,count,count1;

};

#endif // FIRSTCHAPTER_H
