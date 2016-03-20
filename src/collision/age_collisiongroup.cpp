#include "../include/age_collisiongroup.h"

namespace AGE2D {

ACollisionGroup::ACollisionGroup()
{
    this->mode=AGE_C_NORMAL;
}

void ACollisionGroup::add(AShape *shape)
{
    m_list.push_back(shape);
}

AShape *ACollisionGroup::get(int index)
{
    return m_list[index];
}

void ACollisionGroup::setMode(int mode)
{
    this->mode=mode;
}

int ACollisionGroup::getMode()
{
    return this->mode;
}

int ACollisionGroup::size()
{
    return m_list.size();
}

} // namespace AGE2D
