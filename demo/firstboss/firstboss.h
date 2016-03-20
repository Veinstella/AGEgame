#ifndef FIRSTBOSS_H
#define FIRSTBOSS_H
#include "../include/age_spriteactor.h"
#include "../include/age_system.h"
#include "../include/age_accumulator.h"
#include "../include/age_polygon.h"
#include "../include/acircle.h"
using namespace AGE2D;

class FirstBoss:public ASpriteActor
{
public:
    FirstBoss(ATexture *firstboss_texture);

    bool getStep2() const;
    void setStep2(bool value);

    bool getStep1() const;
    void setStep1(bool value);

    bool getStep3() const;
    void setStep3(bool value);

    AVector2D getHero_pos() const;
    void setHero_pos(AVector2D value);

    bool getIs_destory() const;
    void setIs_destory(bool value);
    bool is_destory;

    static ACircle *getFirstboss_circle();
    static void setFirstboss_circle(ACircle *value);

protected:
    void action();

private:
    bool is_in_the_boundary_x(double x);
    bool is_in_the_boundary_y(double y);
    AVector2D hero_pos;
    AAccumulator *fire_cd1;
    AAccumulator *fire_cd2;
    AAccumulator *fire_cd3;
    double angle;
    double speed_x;
    bool go_left;
    bool go_right;
    bool step1;
    bool step2;
    bool step3;
    int count=0;
    static ACircle *firstboss_circle;

};

#endif // FIRSTBOSS_H
