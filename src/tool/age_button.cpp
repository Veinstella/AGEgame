#include "../include/age_button.h"

using namespace AGE2D;

AButton::AButton(ATexture *texture)
{
    bindTexture(texture);
    this->first_texture = texture;
    this->second_texture = texture;
    this->setIsTouchable(true);
}

AButton::AButton(ATexture * texture,ATexture *second_texture)
{
    bindTexture(texture);
    this->first_texture = texture;
    this->second_texture = second_texture;
    this->setIsTouchable(true);
}

void AButton::callTouchedPress(function<void(void)> func)
{
    if(func)
        touchPressFunc = func;
}

void AButton::callTouchedRelease(function<void(void)> func)
{
        if(func)
        {
            isPress = false;
            touchReleaseFunc = func;
        }
}

void AButton::callFocusLost(function<void(void)> func)
{

    if(func)
        touchFocusLostFunc = func;
}

void AButton::OnTouchedPress(AVector2D pos)
{
    isPress = true;
    float m_width = this->width();
    float m_height = this->height();
    this->bindTexture(second_texture);
    this->setSize(m_width,m_height);
    this->setIsTouchable(true);
    if(touchPressFunc)
        touchPressFunc();
}

void AButton::OnTouchedrelease(AVector2D pos)
{
    if(isPress)
    {
        float m_width = this->width();
        float m_height = this->height();
        this->bindTexture(first_texture);
        this->setSize(m_width,m_height);
        this->setIsTouchable(true);
        isPress = false;
        if(touchReleaseFunc)
            touchReleaseFunc();
    }
}

void AButton::OnFocusLost()
{
    float m_width = this->width();
    float m_height = this->height();
    this->bindTexture(first_texture);
    this->setSize(m_width,m_height);
    this->setIsTouchable(true);
    isPress = false;
    if(touchFocusLostFunc)
        touchFocusLostFunc();
}
