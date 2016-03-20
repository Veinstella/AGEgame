#ifndef HeeroBullet_H
#define HeeroBullet_H
#include "../include/age_spriteactor.h"
#include "../include/acircle.h"
using namespace AGE2D;
class HeeroBullet:public ASpriteActor,public ACircle
{
public:
    HeeroBullet(int mods,AVector2D pos,AVector2D hero_pos,double width,double height,double angle,double speed,ATexture *HeeroBullet_texture);

    ACircle *getHeeroBullet_circle() const;
    void setHeeroBullet_circle(ACircle *value);

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
    //ACircle *HeeroBullet_circle;
};

#endif // HeeroBullet_H
