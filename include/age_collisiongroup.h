#ifndef AGE2D_AGE_COLLISIONGROUP_H
#define AGE2D_AGE_COLLISIONGROUP_H
#include "ashape.h"
#include "vector"
using namespace std;
#define AGE_C_NORMAL 0
#define AGE_C_ONLY_MY_GROUP 1
#define AGE_C_IGNORE_MY_GROUP 2
namespace AGE2D {

class ACollisionGroup
{
public:
    ACollisionGroup();
    void add(AShape * shape);
    AShape * get(int index);
        void setMode(int mode);
        int getMode();
        int size();
protected:
        int mode;
    vector<AShape *> m_list;
};

} // namespace AGE2D

#endif // AGE2D_AGE_COLLISIONGROUP_H
