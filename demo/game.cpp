#include "game.h"
//#include "../include/age_layer.h"
#include <QGLFunctions>
//#include "../include/age_baseentity.h"
Game * Game::game;
ATexture *Game::hero_texture;
ATexture *Game::gas_texture;
ATexture *Game::bullet_texture;
ATexture *Game::backgroundtexture_FC1;
ATexture *Game::backgroundtexture_FC2;
ATexture *Game::ai_texture_1;
ATexture *Game::firstboss_texture;
ATexture *Game::hp_texture;
ATexture *Game::bullet_boss_p1;
ATexture *Game::bullet_boss_p2;
ATexture *Game::bullet_boss_p3;

Game *Game::single()
{
	return game;
}

void Game::Init()
{
    game= new Game();
}

Game::Game()
{
    ASystem::SetSize(1080,1920);
    ASystem::GetWidget()->setWindowTitle("AGE");
    //set资源
    bullet_texture= new ATexture(ASystem::Path("resource/effect/effect1.png"));
    gas_texture = new ATexture(ASystem::Path("resource/effect/effect2.png"));
    hero_texture=new ATexture(ASystem::Path("resource/image/hero_animate.png"));
    backgroundtexture_FC1= new ATexture(ASystem::Path("resource/image/menu_earth.png"));
    backgroundtexture_FC2= new ATexture(ASystem::Path("resource/image/menu_earth.png"));
    ai_texture_1= new ATexture(ASystem::Path("resource/image/AI.png"));
    firstboss_texture= new ATexture(ASystem::Path("resource/image/firstboss.png"));
    hp_texture =new ATexture(ASystem::Path("resource/image/naka.png"));
    bullet_boss_p1=new ATexture(ASystem::Path("resource/image/bullet_p1.png"));
    bullet_boss_p2=new ATexture(ASystem::Path("resource/effect/effect1.png"));
    bullet_boss_p3=new ATexture(ASystem::Path("resource/effect/effect2.png"));
    menu = new MenuScene();
    //firstchapter= new FirstChapter();
    deathmenu = new DeathMenu();
    menu->activate();
}

void Game::newfirstchapter()
{
    firstchapter=new FirstChapter();
}

DeathMenu *Game::getDeathmenu() const
{
    return deathmenu;
}

void Game::setDeathmenu(DeathMenu *value)
{
    deathmenu = value;
}

ATexture *Game::getBullet_boss_p3()
{
    return bullet_boss_p3;
}

void Game::setBullet_boss_p3(ATexture *value)
{
    bullet_boss_p3 = value;
}

ATexture *Game::getBullet_boss_p2()
{
    return bullet_boss_p2;
}

void Game::setBullet_boss_p2(ATexture *value)
{
    bullet_boss_p2 = value;
}

ATexture *Game::getBullet_boss_p1()
{
    return bullet_boss_p1;
}

void Game::setBullet_boss_p1(ATexture *value)
{
    bullet_boss_p1 = value;
}


ATexture *Game::getHp_texture()
{
    return hp_texture;
}

void Game::setHp_texture(ATexture *value)
{
    hp_texture = value;
}

ATexture *Game::getFirstboss_texture()
{
    return firstboss_texture;
}

void Game::setFirstboss_texture(ATexture *value)
{
    firstboss_texture = value;
}

ATexture *Game::getAi_texture_1()
{
    return ai_texture_1;
}

void Game::setAi_texture_1(ATexture *value)
{
    ai_texture_1 = value;
}

ATexture *Game::getBackgroundtexture_FC2()
{
    return backgroundtexture_FC2;
}

void Game::setBackgroundtexture_FC2(ATexture *value)
{
    backgroundtexture_FC2 = value;
}

ATexture *Game::getBackgroundtexture_FC1()
{
    return backgroundtexture_FC1;
}

void Game::setBackgroundtexture_FC1(ATexture *value)
{
    backgroundtexture_FC1 = value;
}

ATexture *Game::getBullet_texture()
{
    return bullet_texture;
}

void Game::setBullet_texture(ATexture *value)
{
    bullet_texture = value;
}

ATexture *Game::getHero_texture()
{
    return hero_texture;
}

void Game::setHero_texture(ATexture *value)
{
    hero_texture = value;
}

ATexture *Game::getGas_texture()
{
    return gas_texture;
}

void Game::setGas_texture(ATexture *value)
{
    gas_texture = value;
}


AScene *Game::getCurrent_scence() const
{
    return current_scence;
}

void Game::setCurrent_scence(AScene *value)
{
    current_scence = value;
}


FirstChapter *Game::getFirstchapter() const
{
    return firstchapter;
}



