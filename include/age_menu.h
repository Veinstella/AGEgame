#ifndef AGE_MENU_H
#define AGE_MENU_H

#include "../include/age_button.h"
#include "../include/age_mouselistener.h"
#include "../include/age_spritegroup.h"

#include <map>
#include <list>

namespace AGE2D
{
class AMenu : public AMouseListener,public ASpriteGroup
{
public:
    AMenu();

protected:
    void onMouseMove(AMouseInfo info);
    void onMousePress(AMouseInfo info);
    void onMouseRelease(AMouseInfo info);
    void action();
private:
    AGE2D::AMouseInfo m_info;
};
}


#endif // AGE_MENU_H
