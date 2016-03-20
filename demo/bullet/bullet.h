#ifndef BULLET_H
#define BULLET_H
#include "../include/age_spriteactor.h"
#include "../include/acircle.h"
using namespace AGE2D;
class Bullet:public ASpriteActor,public ACircle
{
public:
    Bullet(int mods,AVector2D pos,AVector2D hero_pos,double width,double height,double angle,double speed,ATexture *bullet_texture);

    ACircle *getBullet_circle() const;
    void setBullet_circle(ACircle *value);

protected:
    void action();

private:
    double angle;
    double speed;
    double increase_x;
    double increase_y;
    //AVector2D hero_pos;
    int mods;
	bool out_of_the_boundary(double x,double y);
    //ACircle *bullet_circle;
};

#endif // BULLET_H
