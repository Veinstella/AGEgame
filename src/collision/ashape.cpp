#include "../include/ashape.h"



AGE2D::AShape::AShape()
{
    this->onCollision=NULL;
}

void AGE2D::AShape::dump()
{
    this->fucked_list.clear();
}

AGE2D::AShape *AGE2D::AShape::collisionItem(int index)
{
    if(index>=this->fucked_list.size()|| index<0)
    {
        return NULL;
    }else
    {
        return this->fucked_list[index];
    }
}

int AGE2D::AShape::getCollistionSize()
{
    return this->fucked_list.size();
}
