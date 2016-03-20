#ifndef PARTICLELAUNCHER_H
#define PARTICLELAUNCHER_H

#include "../include/age_layer.h"
#include "../include/age_vector2d.h"
#include "../include/age_color.h"
#include "../include/particle.h"
#include "../include/age_texture.h"
using namespace AGE2D;
class ParticleLauncher
{
public:
    ParticleLauncher(const char * file,int amount=100);
    void fire(AVector2D where, ALayer * layer);

private:
    int pos_offset_x;
    int pos_offset_y;
    AColor begin_color;
    AColor end_color;
    AVector2D pos;
    AVector2D begin_size;
    AVector2D end_size;
    double angle;
    double rotate_speed;
    AAccumulator * acc;
    int span;
    int amount;
    double width_change_rate;
    double height_change_rate;
    double red_change_rate;
    double green_change_rate;
    double blue_change_rate;
    double begin_angle;
    double end_angle;
    double escape_speed;
    double angle_speed;
    float begin_alpha;
    float end_alpha;
    float alpha_change_rate;
    AVector2D init_pos;
    AVector2D gravity;
    ATexture * texture;
};

#endif // PARTICLELAUNCHER_H
