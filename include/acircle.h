#ifndef AGE2D_ACIRCLE_H
#define AGE2D_ACIRCLE_H

#include "ashape.h"
namespace AGE2D {

class ACircle :public AShape
{
public:
    ACircle();
    virtual void move(AVector2D vec);
    virtual void move(double x,double y);
    AVector2D centre();
    virtual int intersect(AShape * shape);
    virtual int type();
    void setCentre(double x,double y);
    void setCentre(AVector2D vec);
    void setRadius(double a);
    double radius();

   protected:
   AVector2D m_centre;
   double m_radius;
};

} // namespace AGE2D

#endif // AGE2D_ACIRCLE_H
