#ifndef GAME_H
#define GAME_H
#include <QGLShaderProgram>
#include "menu/menuscene.h"
#include "firstchapter/firstchapter.h"
#include "menu/deathmenu.h"
#include "../include/age_scene.h"

using namespace AGE2D;
//管理整个游戏的资源
class Game : public QGLFunctions
{
public:
	static Game * single();
	static void Init();
    void newfirstchapter();
    FirstChapter *getFirstchapter() const;
    AScene *getCurrent_scence() const;
    void setCurrent_scence(AScene *value);

    static ATexture *getGas_texture();
    static void setGas_texture(ATexture *value);

    static ATexture *getHero_texture();
    static void setHero_texture(ATexture *value);

    static ATexture *getBullet_texture();
    static void setBullet_texture(ATexture *value);

    static ATexture *getBackgroundtexture_FC1();
    static void setBackgroundtexture_FC1(ATexture *value);

    static ATexture *getBackgroundtexture_FC2();
    static void setBackgroundtexture_FC2(ATexture *value);

    static ATexture *getAi_texture_1();
    static void setAi_texture_1(ATexture *value);

    static ATexture *getFirstboss_texture();
    static void setFirstboss_texture(ATexture *value);

    static ATexture *getHp_texture();
    static void setHp_texture(ATexture *value);

    static ATexture *getBullet_boss_p1();
    static void setBullet_boss_p1(ATexture *value);

    static ATexture *getBullet_boss_p2();
    static void setBullet_boss_p2(ATexture *value);

    static ATexture *getBullet_boss_p3();
    static void setBullet_boss_p3(ATexture *value);

    DeathMenu *getDeathmenu() const;
    void setDeathmenu(DeathMenu *value);

private:
    Game();
    static Game *game;
    MenuScene * menu;
    DeathMenu * deathmenu;
    FirstChapter *firstchapter;
    AScene *current_scence;
    static ATexture * gas_texture;
    static ATexture * hero_texture;
    static ATexture * bullet_texture;
    static ATexture * backgroundtexture_FC1;
    static ATexture * backgroundtexture_FC2;
    static ATexture * ai_texture_1;
    static ATexture * firstboss_texture;
    static ATexture * hp_texture;
    static ATexture * bullet_boss_p1;
    static ATexture * bullet_boss_p2;
    static ATexture * bullet_boss_p3;

};

#endif // GAME_H
