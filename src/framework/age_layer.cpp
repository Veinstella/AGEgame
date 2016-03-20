#include "../include/age_layer.h"
#include <stdlib.h>
#include <qdebug.h>
#include "../include/age_spritegroup.h"

using namespace std;
namespace AGE2D{
ALayer::ALayer()
{
	this->m_type=LAYER_ENTITY;
	this->m_parent=NULL;
}

ALayer::ALayer(ASprite *spritePointer)
{
	this->m_type=LAYER_ENTITY;
	this->m_parent=NULL;
    addChild(spritePointer);
}

void ALayer::addChild(ASprite *spritePointer)
{
	AScene *scene =m_parent;
    if(m_parent)
	{
		scene->insertBaseEntity (spritePointer);
		spritePointer->m_parent=this;
        m_spriteList.push_back(spritePointer);
	}
}

void ALayer::addChild(ASpriteGroup *spriteGroupPointer)
{
    AScene * scene = m_parent;
    if(m_parent)
    {
        for(list<ASprite*>::iterator it = spriteGroupPointer->sprite_list.begin();
            it != spriteGroupPointer->sprite_list.end();++it)
        {
            ASprite * temp = *it;
            this->addChild(temp);
            qDebug()<<"hehe";
        }
        scene->insertBaseEntity(spriteGroupPointer);
        spriteGroupPointer->m_parent = this;
        m_spriteGroupList.push_back(spriteGroupPointer);
    }
}

void ALayer::setName(string new_name)
{
	if(m_parent)
	{
		AScene *scene=m_parent;
		scene->updateBaseEntity (this->name (),new_name);
	}
    this->identity_name=new_name;
}

AScene *ALayer::parent()
{
    return m_parent;
}

int ALayer::checkPress(AVector2D pos)
{
    for(list<ASprite*>::reverse_iterator i = m_spriteList.rbegin();i!=m_spriteList.rend();i++)
    {
        ASprite * tmp=(*i);
        if(tmp->isTouchable())
        {
            APolygon polygon=tmp->getPolygon();
            if(polygon.pointInPolygon(pos)==1 && tmp->isHide() == false)
            {

                tmp->OnTouchedPress(pos);
                return 1;
            }
        }
    }
    return 0;
}

void ALayer::moveToEnd(ASprite *spritePointer)
{
    ASprite * temp = spritePointer;

    list<ASprite *>::iterator it = find(m_spriteList.begin(),m_spriteList.end(),spritePointer);
    m_spriteList.erase(it);
    m_spriteList.push_back(temp);
}

int ALayer::checkRelease(AVector2D pos,int mode)
{
    bool is_checked=false;
    for(list<ASprite*>::reverse_iterator i = m_spriteList.rbegin();i!=m_spriteList.rend();i++)
    {
        ASprite * tmp=(*i);
        if(tmp->isTouchable())
        {
            APolygon polygon=tmp->getPolygon();
            if(!is_checked &&polygon.pointInPolygon(pos)==1 && tmp->isHide() == false&&mode==1)
            {
                tmp->is_get_focused=true;
                tmp->touch_state=AGE_SPRITE_TOUCHED;
                tmp->OnTouchedrelease(pos);
                is_checked=true;
                qDebug()<<"touch in sprite";
            }
            else
            {
                if(!tmp->is_get_focused && tmp->isHide() == false)
                {
                    tmp->is_get_focused=false;
                    tmp->touch_state=AGE_SPRITE_LOST_FOCUS;
                    tmp->OnFocusLost();
                }

                if(tmp->is_get_focused && tmp->isHide() == false)
                {
                    tmp->is_get_focused=false;
                    tmp->touch_state=AGE_SPRITE_LOST_FOCUS;
                    tmp->OnFocusLost();
                }
            }
        }
    }
    if(is_checked || mode==0)
    {
        return 0;
    }else
    {
        return 1;
    }
}

void ALayer::renderLayer()
{
    for(list<ASprite*>::iterator alpha_it = m_spriteList.begin();
    alpha_it != m_spriteList.end();)
    {
    if((*alpha_it)->isDeath == true)
    {
        ASprite *temp = *alpha_it;
        temp->release();
        delete temp;
        alpha_it = m_spriteList.erase(alpha_it);
    }
    else
    {
        ASprite * temp = *alpha_it;
        if(temp->m_isHide == false)
        {
            temp->action();
            temp->render();
            temp->dumpTouchState();
        }
        alpha_it++;
    }
    }

    for(list<ASpriteGroup *>::iterator alpha_it = m_spriteGroupList.begin();
        alpha_it != m_spriteGroupList.end();
        )
    {
        if((*alpha_it)->isDeath == true)
        {
            ASpriteGroup *temp = *alpha_it;
            temp->release();
            delete temp;
            alpha_it = m_spriteGroupList.erase(alpha_it);
        }
        else
        {
            ASpriteGroup * temp = *alpha_it;
            if(temp->m_isHide == false)
            {
                temp->action();
            }
            alpha_it++;
        }
    }
    //qDebug()<<m_spriteList.size();
}

void ALayer::action()
{

}

}
