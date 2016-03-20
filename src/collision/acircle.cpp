#include "../include/acircle.h"
#include <math.h>
#include <../include/age_polygon.h>
namespace AGE2D {

ACircle::ACircle()
{
    this->m_centre.setX(0);
    this->m_centre.setY(0);
}

void ACircle::move(AVector2D vec)
{
    this->move(vec.x(),vec.y());
}

void ACircle::move(double x, double y)
{
    this->m_centre.setX(m_centre.x()+x);
    this->m_centre.setY(m_centre.y()+y);
}

int ACircle::intersect(AShape *shape)
{
    if(shape->type()==AGE_CIRCLE)
    {
        ACircle * circle=(ACircle*)shape;
       double dist=sqrt(pow(circle->centre().x()-m_centre.x(),2)
             +
             pow(circle->centre().y()-m_centre.y(),2));
       if(dist<=m_radius+circle->radius())
       {
           if(this->onCollision)
           {
               this->onCollision(circle);
               this->fucked_list.push_back(circle);
           }
           return 1;
       }
       else {
           return 0;
       }
    }else
        if(shape->type()==AGE_POLYGON)
        {
            APolygon * poly=(APolygon*)shape;
            for(int i=0;i<poly->totalVertices();i++)
            {
                double dist=sqrt(pow(poly->vertex(i).x()-m_centre.x(),2)
                      +
                      pow(poly->vertex(i).y()-m_centre.y(),2));
                if(dist<=this->m_radius)
                {
                this->onCollision(poly);
                    this->fucked_list.push_back(poly);
                 return 1;
                }
            }
            return 0;
        }
}

int ACircle::type()
{
    return AGE_CIRCLE;
}

void ACircle::setCentre(double x, double y)
{
    this->m_centre.setX(x);
    this->m_centre.setY(y);
}

void ACircle::setCentre(AVector2D vec)
{
    this->setCentre(vec.x(),vec.y());
}

void ACircle::setRadius(double a)
{
    this->m_radius=a;
}

double ACircle::radius()
{
    return this->m_radius;
}

AVector2D ACircle::centre()
{
    return this->m_centre;
}

} // namespace AGE2D
