#ifndef AGE_BUTTON_H
#define AGE_BUTTON_H
#include "../include/age_spriteactor.h"
#include <functional>

#define LINKFUNCTION(function,object) bind(&function,object)

namespace AGE2D {
class AButton : public ASpriteActor
{
public:
    AButton(ATexture *texture);
    AButton(ATexture * texture,ATexture *second_texture);
    void callTouchedPress(function<void(void)> func);
    void callTouchedRelease(function<void(void)> func);
    void callFocusLost(function<void(void)> func);

protected:
    void OnTouchedPress(AVector2D pos);
    void OnTouchedrelease(AVector2D pos);
    void OnFocusLost();

private:
    ATexture * second_texture;
    ATexture * first_texture;
    function<void(void)> touchPressFunc;
    function<void(void)> touchReleaseFunc;
    function<void(void)> touchFocusLostFunc;
    bool isPress = false;
};
}

#endif // AGE_BUTTON_H
