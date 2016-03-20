#ifndef HP_H
#define HP_H
#include "../include/age_sprite.h"
using namespace AGE2D;

class Hp : public ASprite
{
public:
    Hp();
    float getGet_wight() const;
    void setGet_wight(float value);
    void destroy();
    void change_hp();

protected:
    void action();
private:
    float hold_wight;
    float start_wight;
    float get_wight;
    int i=1;
};


#endif // HP_H
