#ifndef AMOUSEEVENT_H
#define AMOUSEEVENT_H

#include "../include/age_vector2d.h"

namespace AGE2D{
class AMouseInfo
{
public:
    AMouseInfo();
    void setMouseX(int mouseX);
    void setMouseY(int mouseY);
    int getMouseX();
    int getMouseY();
    int x();
    int y();
    AVector2D pos();
    AMouseInfo & operator = (const AMouseInfo & temp)
    {
        m_mouseX = temp.m_mouseX;
        m_mouseY = temp.m_mouseY;
        return *this;
    }

private:
    int m_mouseX;
    int m_mouseY;
};

}

#endif // AMOUSEEVENT_H
