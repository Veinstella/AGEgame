#ifndef ASHAPE_H
#define ASHAPE_H
#include "../include/age_vector2d.h"
#include "vector"
using namespace std;
namespace  AGE2D {
#define AGE_POLYGON 1
#define AGE_CIRCLE 2
class AShape
{
public:
     AShape();
    virtual void move(AVector2D vec)=0;
    virtual void move(double x,double y)=0;
    virtual int intersect(AShape * shape)=0;
    virtual int type()=0;
    void (* onCollision)(AShape * you);
    void dump();
    AShape * collisionItem(int index);
    int getCollistionSize();
protected:
    vector<AShape*> fucked_list;
};
}


#endif // ASHAPE_H
