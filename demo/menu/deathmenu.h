#ifndef DEATHMENU_H
#define DEATHMENU_H

#include "../include/age_scene.h"
#include "../include/age_mouselistener.h"
#include "../include/age_font.h"
#include "../include/age_audio.h"

using namespace AGE2D;

class DeathMenu : public AScene,public AMouseListener
{
public:
    DeathMenu();

protected:
    void action();
    void onMousePress(AMouseInfo info);
    void onMouseRelease(AMouseInfo info);
    void onMouseMove(AMouseInfo info);

private:
    ATexture * button_texture;
    ATexture * deathmenu_background_texture;

    ASprite * restart_button_sprite;
    ASprite * exit_button_sprite;
    ASprite * deathmenu_background_sprite;

    AFont * restart_font;
    AFont * exit_font;
    AFont * gameover_font;

    AAudio * deathmenu_music;

};


#endif // DEATHMENU_H
