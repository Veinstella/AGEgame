#ifndef AGE2D_AGE_UTILITY_H
#define AGE2D_AGE_UTILITY_H
#include "../include/age_vector2d.h"
namespace AGE2D {

class AUtility
{
public:
    static bool IsOutOfBoundary(AVector2D pos);
private:
    AUtility();
};

} // namespace AGE2D

#endif // AGE2D_AGE_UTILITY_H
