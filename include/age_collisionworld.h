#ifndef AGE_COLLISIONWORLD_H
#define AGE_COLLISIONWORLD_H
#include "age_collisiongroup.h"
#include "ashape.h"
#include "list"
using namespace std ;
namespace AGE2D {
struct group_info{
    ACollisionGroup * group;
    int index;
};
class A_CollisionWorld
{
public:

    A_CollisionWorld();
    int add();
    ACollisionGroup *get(int index);
    void go();
    void dump();
protected:
    void handleOnlyMyGroup(ACollisionGroup * group);
    void handleIgnoreMyGroup(ACollisionGroup * group);
    int index;
    list<group_info *> m_list ;
};
}


#endif // AGE_COLLISIONWORLD_H
