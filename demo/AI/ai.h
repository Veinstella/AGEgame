#ifndef AI_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_accumulator.h"
#include "../include/age_audio.h"
#include "../include/age_framelistener.h"
#include "../include/age_frame.h"
#include "../include/particle.h"
#include "../include/particlelauncher.h"
#include <time.h>
#define AI_H
//1080*1920
using namespace AGE2D;
class Ai :public ASprite,public AFrameListener
{
protected:
     AAccumulator *fire_cd;
     AAccumulator *AiNum;
     AAccumulator *stayTime;
     bool is_firing;
     int from;
     float inX;
     float inY;
     float outX;
     float outY;
     float stayX;
     float stayY;
     int num;
     int stime;
     int cd;
     int width;
     int height;
     int shotMods;
public:
    Ai(ATexture *ai_texture,int stayTime,int width,int height,int shotMods);
    void InIt()
    {
        from = 0;
        inX = 0.0;
        inY = 0.0;
        outX = 0.0;
        outY = 0.0;
        stayX = 0.0;
        stayY = 0.0;
        is_firing = false;
    }
    int getRand(int s);
    void action();
    void AiIn(float x,float y);
    void AiStay();
    void AiOut(float x,float y);
};

#endif // AI_H
