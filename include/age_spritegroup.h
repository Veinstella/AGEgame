#ifndef AGE_SPRITEGROUP_H
#define AGE_SPRITEGROUP_H

#include "age_layer.h"
#include "age_baseentity.h"
#include "age_sprite.h"
#include <list>

namespace AGE2D{
#define ASGGROUPLIST list<ASprite*>::iterator

class ASpriteGroup : public ABaseEntity
{
public:
    ASpriteGroup();
    ~ASpriteGroup();
    void addChild(ASprite *);
    void hide();
    void show();
    bool isHide();
    void setX(float x);
    void setY(float y);
    void setPos(AVector2D temp);
    void setPos(float x,float y);
    AVector2D pos();
    float x();
    float y();

    std::list<ASprite*>::iterator begin();
    std::list<ASprite*>::iterator end();


    friend class ALayer;

protected:
    virtual void action();
    virtual void release();
private:
    void initPos(int x,int y);
    ALayer * m_parent = NULL;
    bool isDeath = false;
    bool m_isHide = false;
    float m_x;
    float m_y;
    std::list<ASprite *> sprite_list;
};

}
#endif // AGE_SPRITEGROUP_H
