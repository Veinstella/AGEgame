#include "../include/age_effect.h"

using namespace AGE2D;
using namespace std;

AEffect::AEffect(ATexture *texture,AAnimationSet *animationSet,QString animationName,int frame_num)
{
    bindTexture(texture);

    this->animationSet = animationSet;
    if(animationSet != NULL)
        bindAnimationSet(animationSet);
    this->animationName = animationName;
    max_frame = 3;
    this->frame_num = frame_num;
    this->setSize(60,60);
    this->setAlpha(0);
}

void AEffect::setFrame(int max_frame)
{
    this->max_frame = max_frame;
}

void AEffect::action()
{
    this->setAlpha(100);
    frame_go++;
    if(frame_go % max_frame == 1 && animationSet != NULL && animationName != "")
    {
        if(frame == frame_num)
        {
            frame = frame_num;
            this->destroy();
            return;
        }
        animate(animationName,frame,true);
        frame++;
    }
}
