#include <../include/age_polygon.h>
#include <math.h>
#include <QVector3D>
#include <QDebug>
#include "../include/acircle.h"
using namespace std;
namespace AGE2D
{
#define EPSILON 0.00001

APolygon::APolygon()
{
}

void APolygon::addPoint(double x, double y)
{
    m_pointList.push_back(AVector2D(x,y));
}

void APolygon::addPoint(AVector2D vec)
{
    m_pointList.push_back(vec);
}

AVector2D APolygon::vertex(int index)
{
    return this->m_pointList[index];
}

int APolygon::totalVertices()
{
    return this->m_pointList.size();
}


void APolygon::move(AVector2D vec)
{
    this->move(vec.x(),vec.y());
}

void APolygon::move(double x, double y)
{
    for(std::vector<AVector2D>::iterator it = m_pointList.begin();
    it!= m_pointList.end();
        ++it)
    {
        AVector2D tmp=(*it);
        tmp.setX(tmp.x()+x);
        tmp.setY(tmp.y()+y);
    }


}

int APolygon::intersect(AShape *shape)
{
    if(shape->type()==AGE_POLYGON)
    {
        APolygon * poly=(APolygon *)shape;
        for(int i=0;i<poly->totalVertices();i++)
        {
              if(this->pointInPolygon(poly->vertex(i)))
              {
                  if(this->onCollision)
                  {
                      this->onCollision(poly);
                      this->fucked_list.push_back(poly);
                  }
                  return 1;
              }
        }
        for(int i=0;i<this->totalVertices();i++)
        {
              if(poly->pointInPolygon(this->vertex(i)))
              {
                  if(this->onCollision)
                  {
                      this->onCollision(poly);
                      this->fucked_list.push_back(poly);
                  }
                  return 1;
              }
        }
        return 0;
    }
    else if(shape->type()==AGE_CIRCLE)
    {
        ACircle * circle=(ACircle * )shape;
        for(int i=0;i<this->totalVertices();i++)
        {
            double dist=sqrt(pow(this->vertex(i).x()-circle->centre().x(),2)
                  +
                  pow(this->vertex(i).y()-circle->centre().y(),2));
            if(dist<=circle->radius())
            {
            this->onCollision(circle);
                this->fucked_list.push_back(circle);
             return 1;
            }
        }
    }
}

int APolygon::type()
{
    return AGE_POLYGON;
}

// Globals which should be set before calling this function:
//
// int    polySides  =  how many corners the polygon has
// float  polyX[]    =  horizontalcoordinates of corners
// float  polyY[]    =  verticalcoordinates of corners
// float  x,y       =  point to be tested
//
// (Globals are used in this example for purposes of speed.  Change as
// desired.)
//
//  Thefunction will return YES if the point x,y is inside the polygon, or
//  NOif it is not.  If the point is exactly on the edge of the polygon,
// then the function may return YES or NO.
//
// Note that division by zero is avoided because the division is protected
//  bythe "if" clause which surrounds it.

bool point_in_polygon(float x, float y,float polyX[],float polyY[],int polySides) {

  int   i,j=polySides-1 ;
  bool  oddNodes=false;

  for (i=0;i<4; i++) {
    if((polyY[i]< y && polyY[j]>=y
    ||   polyY[j]<y && polyY[i]>=y)
    && (polyX[i]<=x || polyX[j]<=x))
    {
      oddNodes^=(polyX[i]+(y-polyY[i])/(polyY[j]-polyY[i])*(polyX[j]-polyX[i])<x);
    }
    j=i;}
  return oddNodes;
}


float polyX[100];
float polyY[100];
int APolygon::pointInPolygon(AVector2D poPoint)
{
	double X = poPoint.x();
	double Y = poPoint.y();

    for(std::vector<AVector2D>::iterator it = m_pointList.begin();
    it!= m_pointList.end();
        ++it)
    {
  //      qDebug()<<(*it);
    }
    int i=0;
    for(std::vector<AVector2D>::iterator it = m_pointList.begin();
	it!= m_pointList.end();
        ++it,++i)
	{
        AVector2D tmp=(*it);
    polyX[i]=tmp.x();
    polyY[i]=tmp.y();
	}

    if(point_in_polygon(X,Y,polyX,polyY,this->m_pointList.size()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int APolygon::IsIntersectAnt(double x, double y, double X1, double Y1, double X2, double Y2)
{

    AVector2D  far_point(1000,1000);
    AVector2D touch_point(x,y);
    AVector2D line_point1(X1,Y1);
    AVector2D line_point2(X2,Y2);
    QVector3D line_1=line_point2 -line_point1;
    QVector3D line_2=far_point -line_point1;
    QVector3D line_3=touch_point - line_point1;

    QVector3D cross_product_1=QVector3D::crossProduct (line_2,line_1);
    QVector3D cross_product_2=QVector3D::crossProduct (line_3,line_1);
    int result1=cross_product_1.z ()*cross_product_2.z ();


     line_1=far_point -touch_point;
     line_2=line_point1 -touch_point;
     line_3=line_point2 - touch_point;
     cross_product_1=QVector3D::crossProduct (line_2,line_1);
     cross_product_2=QVector3D::crossProduct (line_3,line_1);
     int result2=cross_product_1.z ()*cross_product_2.z ();

     if(result2<-EPSILON&& result1<-EPSILON)//相互跨立,所以线段相交
     {
	 return 1;
     }
     else if(fabs(result1)<EPSILON ||fabs(result2)<EPSILON ) //点在线上
     {
	 return -1;
     }
     else
     {
	 return 0;
     }

}

int APolygon::pointInPolygon2(AVector2D poPoint)
{
    QVector3D p(poPoint.x(),poPoint.y(),0);
    for(std::vector<AVector2D>::iterator it = m_pointList.begin();
	it!= m_pointList.end()-1;
	++it);
    return 0;
}

}

