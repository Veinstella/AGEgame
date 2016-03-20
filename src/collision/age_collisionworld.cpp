#include "../include/age_collisionworld.h"
namespace AGE2D {
A_CollisionWorld::A_CollisionWorld()
{
index=0;


}

int A_CollisionWorld::add()
{
    ++index;
    group_info * info=new group_info();
    m_list.push_back(new group_info());
    info->group=new ACollisionGroup();
    info->index=index;
    return index;
}

ACollisionGroup *A_CollisionWorld::get(int index)
{
    for(list<group_info*>::iterator i=m_list.begin(); i!=m_list.end();i++)
    {
        group_info * info= (*i);
        if(info->index==index)
        {
            return info->group;
        }
    }
    return NULL;
}

void A_CollisionWorld::go()
{
    dump();
    for(list<group_info*>::iterator i=m_list.begin(); i!=m_list.end();i++)
    {
        group_info * info= (*i);
        ACollisionGroup * group=info->group;
        switch(group->getMode())
        {
            case AGE_C_ONLY_MY_GROUP:
                handleOnlyMyGroup(group);
            break;
        case AGE_C_IGNORE_MY_GROUP:
            handleIgnoreMyGroup(group);
            break;
        case AGE_C_NORMAL:
            handleOnlyMyGroup(group);
            handleIgnoreMyGroup(group);
            break;
         default:
    //error
            break;
        }
    }
}

void A_CollisionWorld::dump()
{
    for(list<group_info*>::iterator i=m_list.begin(); i!=m_list.end();i++)
    {
        group_info * info= (*i);
        ACollisionGroup * group=info->group;
        for(int i=0;i<group->size();i++)
        {
            group->get(i)->dump();
        }
    }
}

void A_CollisionWorld::handleOnlyMyGroup(ACollisionGroup * group)
{
    for(int i=0;i<group->size();i++)
    {
        for(int j=i+1;j<group->size();j++)
        {
            group->get(i)->intersect(group->get(j));
        }
    }
}

void A_CollisionWorld::handleIgnoreMyGroup(ACollisionGroup *group)
{

    for(int i=0;i<group->size();i++)
    {
        for(list<group_info*>::iterator t=m_list.begin(); t!=m_list.end();t++)
        {
        group_info * tmp_info= (*t);
        ACollisionGroup * tmp_group=tmp_info->group;
        if(tmp_group==group)
            continue;

        for(int j=0;j<tmp_group->size();j++)
        {
                group->get(i)->intersect(group->get(j));
        }

        }


    }



}


}

