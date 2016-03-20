#ifndef BACK_GROUND_H
#define BACK_GROUND_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_system.h"
#include "AI/ai.h"
//#include "game.h"

using namespace AGE2D;

class BackGround:public ASprite
{
private:
    float speed;
    float offset_x;
    float offset_y;
    bool is_move_x;
    bool is_move_y;
    bool is_photo_cycle;

protected:
    void action();

public:
    BackGround(ATexture *background_texture);

    bool getIs_move_x() const;
    void setIs_move_x(bool value);
    bool getIs_move_y() const;
    void setIs_move_y(bool value);
    bool getIs_photo_cycle() const;
    void setIs_photo_cycle(bool value);

    float getSpeed() const;
    void setSpeed(float value);
    float getOffset_x() const;
    void setOffset_x(float value);
    float getOffset_y() const;
    void setOffset_y(float value);
};


#endif // BACK_GROUND_H
