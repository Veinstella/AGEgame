#include "menu/deathmenu.h"
#include "game.h"
#include <QDebug>

DeathMenu::DeathMenu()
{
    button_texture= new ATexture(ASystem::Path("resource/image/menu_choose.png"));

    restart_button_sprite = new ASprite(button_texture);
    exit_button_sprite = new ASprite(button_texture);
    deathmenu_background_sprite= new ASprite(Game::getBackgroundtexture_FC1());

    restart_font = new AFont(200,100,100,ASystem::Path("resource/font/simplified_chs.ttf").toStdString().data());
    exit_font = new AFont(200,100,100,ASystem::Path("resource/font/simplified_chs.ttf").toStdString().data());
    gameover_font = new AFont(300,100,100,ASystem::Path("resource/font/simplified_chs.ttf").toStdString().data());

    setListenerManager(new AEventMgr());
    eventMgr()->addMouseListener(this);

    this->layer(1)->addChild(restart_button_sprite);
    this->layer(1)->addChild(exit_button_sprite);
    this->layer(1)->addChild(deathmenu_background_sprite);

    restart_button_sprite->setPos(AVector2D(ASystem::GetWidth()/2-restart_button_sprite->width()/2,
                                            restart_button_sprite->height()*3+100));
    exit_button_sprite->setPos(AVector2D(ASystem::GetWidth()/2-exit_button_sprite->width()/2,
                                         exit_button_sprite->height()*2));
    deathmenu_background_sprite->setPos(AVector2D(-deathmenu_background_sprite->width()/3,
                                                  -deathmenu_background_sprite->height()/2));

    restart_font->print("重开",restart_button_sprite->getX()+50,restart_button_sprite->getY()+100,this->layer(1));
    exit_font->print("退出",exit_button_sprite->getX()+50,exit_button_sprite->getY()+100,this->layer(1));
    gameover_font->print("GAME OVER",ASystem::GetWidth()/2-restart_button_sprite->width(),
                         restart_button_sprite->height()*5,this->layer(1));



}

void DeathMenu::action()
{

}

void DeathMenu::onMouseMove(AMouseInfo info)
{

}

void DeathMenu::onMousePress(AMouseInfo info)
{

}

void DeathMenu::onMouseRelease(AMouseInfo info)
{
    AVector2D mouse_press;
    mouse_press.setX(info.getMouseX());
    mouse_press.setY(info.getMouseY());
    if(restart_button_sprite->getPolygon().pointInPolygon(mouse_press))
    {
        Game::single()->getFirstchapter()->destroy();
        delete Game::single()->getFirstchapter();
        Game::single()->newfirstchapter();
        Game::single()->getFirstchapter()->activate();
        Game::single()->getFirstchapter()->getFC_music()->play();
        Game::single()->setCurrent_scence(Game::single()->getFirstchapter());
    }

    if(exit_button_sprite->getPolygon().pointInPolygon(mouse_press))
        exit(0);
}
