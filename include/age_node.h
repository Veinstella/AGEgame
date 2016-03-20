#ifndef ANODE_H
#define ANODE_H
#include "age_vector2d.h"


namespace AGE2D {
class AMatrix4x4;
class ANode
{
public:
    ANode();
    ~ANode();
    virtual AMatrix4x4 getMatrix();
    virtual void setX(float x);
    virtual void setY(float y);
    virtual void setPos(AVector2D pos);
    virtual void setPos(float x,float y);
    virtual void setScale(float value);
    virtual float getX();
    virtual float getY();
    virtual float x();
    virtual float y();
    virtual AVector2D pos();
    virtual float getScale();
    virtual float setAnchorPos(AVector2D temp);
    virtual float setAnchorPos(float x,float y);
    virtual float setAnchorPosX(float x);
    virtual float setAnchorPosY(float y);
private:
    float m_x;
    float m_y;
    float m_scale;
    float anchorPos_x = 0;
    float anchorPos_y = 0;
};
}


#endif // ANODE_H
