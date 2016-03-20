#include "../include/age_utility.h"
#include "../include/age_system.h"
namespace AGE2D {

bool AUtility::IsOutOfBoundary(AVector2D pos)
{
    if(pos.x()>ASystem::GetWidth() || pos.x()<0 || pos.y()>ASystem::GetHeight() || pos.y()<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

AUtility::AUtility()
{
}

} // namespace AGE2D
