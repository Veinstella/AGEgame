#include "../include/age_spritegroup.h"

using namespace AGE2D;


ASpriteGroup::ASpriteGroup()
{
}

void ASpriteGroup::addChild(ASprite * sprite)
{
    sprite_list.push_back(sprite);

    if(m_parent != NULL)
    {
        m_parent->addChild(sprite);
    }
}

ASpriteGroup::~ASpriteGroup()
{

}

void ASpriteGroup::release()
{

}

list<ASprite*>::iterator ASpriteGroup::begin()
{
    return sprite_list.begin();
}

list<ASprite*>::iterator ASpriteGroup::end()
{
    return sprite_list.end();
}

void ASpriteGroup::hide()
{
    for(ASGGROUPLIST it = this->begin();
        it != this->end();
        ++it)
    {
        ASprite * sprite = *it;
        sprite->hide();
    }
    m_isHide = true;
}

bool ASpriteGroup::isHide()
{
    return m_isHide;
}

void ASpriteGroup::show()
{
    for(ASGGROUPLIST it = this->begin();
        it != this->end();
        ++it)
    {
        ASprite * sprite = *it;
        sprite->show();
    }
    m_isHide = false;
}

void ASpriteGroup::action()
{

}

void ASpriteGroup::setX(float x)
{
    m_x = x;
    initPos(m_x,m_y);
}

void ASpriteGroup::setY(float y)
{
    m_y = y;
    initPos(m_x,m_y);
}

void ASpriteGroup::setPos(AVector2D temp)
{
    m_x = temp.x();
    m_y = temp.y();
    initPos(m_x,m_y);
}

void ASpriteGroup::setPos(float x,float y)
{
    m_x = x;
    m_y = y;
    initPos(m_x,m_y);
}

float ASpriteGroup::x()
{
    return m_x;
}

float ASpriteGroup::y()
{
    return m_y;
}

AVector2D ASpriteGroup::pos()
{
    return AVector2D(m_x,m_y);
}

void ASpriteGroup::initPos(int x, int y)
{
    for(ASGGROUPLIST it = this->begin();
        it != this->end();
        ++it)
    {
        ASprite * sprite = *it;
        sprite->setAnchorPos(this->pos());
    }
}
