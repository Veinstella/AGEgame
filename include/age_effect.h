#ifndef AGE_EFFECT_H
#define AGE_EFFECT_H

#include "../include/age_spriteactor.h"

class AEffect : public AGE2D::ASpriteActor
{
public:
    AEffect(AGE2D::ATexture *texture,AGE2D::AAnimationSet *animationSet = NULL,QString animationName = "",int frame_num = 3);
    void setFrame(int max_frame);
    int max_frame = 0;
    int frame_go = 0;
    int frame = 0;
    int frame_num;
    QString animationName;
    AGE2D::AAnimationSet * animationSet = NULL;
protected:
    virtual void action();

private:

};

#endif // AGE_EFFECT_H
