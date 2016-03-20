#ifndef ALAYER_H
#define ALAYER_H
#include <list>
#include "age_scene.h"
#include "age_sprite.h"
#include "age_baseentity.h"
#include <qglfunctions.h>

namespace AGE2D {

class ASprite;
class AScene;
class ASpriteGroup;

class ALayer : public QGLFunctions ,public ABaseEntity
{
public:
    ALayer();

    ALayer(ASprite * spritePointer);
    void addChild(ASprite * spritePointer);
    void addChild(ASpriteGroup *spriteGroupPointer);

    virtual void setName(std::string new_name);
    friend class AScene;
    AScene * parent();
    int checkPress(AVector2D pos);
    int checkRelease(AVector2D pos,int mode);
    void moveToEnd(ASprite *spritePointer);
protected:
    virtual void action();
    AScene * m_parent;
private:
    std::list<ASprite *> m_spriteList;
    std::list<ASpriteGroup *> m_spriteGroupList;//精灵组组

    void renderLayer();
};
}


#endif // ALAYER_H
