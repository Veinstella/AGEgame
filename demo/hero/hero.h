#ifndef HERO_H
#define HERO_H
#include "../include/age_spriteactor.h"
#include "../include/age_texture.h"
#include "../include/age_keylistener.h"
#include "../include/age_accumulator.h"
#include "../include/age_audio.h"
#include "../include/age_mouselistener.h"
#include "../include/age_mouseinfo.h"
#include "../include/age_animation.h"
#include "../include/age_animationset.h"
#include "../include/age_polygon.h"
#include "../include/acircle.h"
#include "../include/particle.h"
#include "../include/particlelauncher.h"
#include <bullet/heerobullet.h>
#include "age_sound.h"

using namespace AGE2D;
class Hero :public ASpriteActor,public AKeyListener,public AMouseListener
{
private:
    bool is_in_the_boundary_x(double x);
    bool is_in_the_boundary_y(double y);
    bool turn_left;
    bool turn_right;
    bool fore_ward;
    bool back_ward;
    bool sneak;
    bool is_firing;
    bool put_mouse;
    AAccumulator *fire_cd;
    AAccumulator *frame_static;
    AAccumulator *frame_left;
    AAccumulator *frame_right;
    AVector2D  mousePos;
    float angle;
    float length;
    float fuck = 0;
    AAnimationSet *animationset;
    QString hero_name;
    AAudio *bullet_music;
    static ACircle *hero_circle;
    ParticleLauncher *hero_particle;

    ASound *trymusic;
protected:
    virtual void onKeyRelease(QKeyEvent * event);
    virtual void onKeyPress (QKeyEvent *event);
    virtual void onMouseMove(AMouseInfo info);
    virtual void onMouseRelease(AMouseInfo info);
    virtual void onMousePress(AMouseInfo info);
    virtual void action();
public:
    Hero(ATexture *hero_texture);

    AAudio *getBullet_music() const;
    void setBullet_music(AAudio *value);
    static ACircle *getHero_circle();
    static void setHero_circle(ACircle *value);
};

#endif // HERO_H
