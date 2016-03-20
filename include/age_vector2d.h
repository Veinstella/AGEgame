#ifndef AVECTOR2D_H
#define AVECTOR2D_H

#include <QVector2D>
#include "age_point.h"
#include "age_pointf.h"
#include "age_vector3d.h"
#include "age_vector4d.h"
namespace AGE2D {

class AVector2D : public QVector2D
{
public:
    AVector2D();
    AVector2D(float xpos,float ypos);
    AVector2D(const APoint &point);
    AVector2D(const AVector3D &vector);
    AVector2D(const AVector4D &vector);

    bool operator < (const AVector2D & temp) const
    {
        return false;
    }

    AVector2D  &operator = (const AVector2D & temp)
    {
        this->setX(temp.x());
        this->setY(temp.y());
        return *this;
    }

    bool operator == (const AVector2D & temp) const
    {
        if(x() == temp.x() && y() == temp.y())
            return true;
        return false;
    }

};
}


#endif // AVECTOR2D_H
