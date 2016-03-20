#ifndef ASPRITE_H
#define ASPRITE_H

#include <QGLShaderProgram>
#include <../include/age_node.h>
#include <../include/age_geometric.h>
#include <../include/age_texture.h>
#include <../include/age_baseentity.h>
#include <memory>
#include "age_polygon.h"
#include "age_layer.h"
#include "age_texture.h"
#include "age_geometric.h"
#include "age_node.h"
#include "age_vector2d.h"
#include "age_color.h"
#include <stdlib.h>
namespace AGE2D {
#define AGE_SPRITE_TOUCH_NOT_ACTIVE -1
#define AGE_SPRITE_TOUCH_NULL 0
#define AGE_SPRITE_TOUCHED 1
#define AGE_SPRITE_LOST_FOCUS 2

class ALayer;
class ASprite : public ANode,protected QGLFunctions,public ABaseEntity
{
public:
    int touchState();

    virtual void render();
    virtual ~ASprite();
    friend class ALayer;
    ASprite();
    ASprite(ATexture *);
    void setShowRect(float lx,float ly,float rx,float ry);
    void setShowDet(int row,int col,int gridWidth,int gridHeigth);

    void bindTexture(ATexture * fuckyou);
    void bindTexture(int textureId,int width,int height);
    int getTextureId();
    void loadShaderProgram(QGLShaderProgram *);
    void initGeometric();

    void setPivotOffset(float x_offset,float y_offset); //Set the axis
    void rotate(float angle);
    void setColor(float r,float g,float b);
    void setColor(long int rgb);
    APolygon getPolygon();
    void setIsTouchable(bool is_touchable);
    bool isTouchable();
    AColor getColor();

    void setAlpha(float alpha);
    float getAlpha();
    float leftTopX();
    float leftTopY();
    AVector2D leftTop();

    float rightTopX();
    float rightTopY();
    AVector2D rightTop();

    float leftBottonX();
    float leftBottonY();
    AVector2D leftBotton();

    float rightBottonX();
    float rightBottonY();
    AVector2D rightBotton();

    float middleX();
    float middleY();
    AVector2D middle();

    float width();
    float height();
    AVector2D size();
    void setSize(float width,float height);
    void destroy();
    QGLShaderProgram *getShaderProgram();
    void setWidth(float);
    void setHeight(float);
    bool isDie();
    int isHover(AVector2D pos);
    ALayer * parent();
    bool isHide();
    void hide();
    void show();

    virtual void setName(std::string new_name);

    //friend class ALayer;
protected:
    bool is_get_focused;
    bool is_touchable;
    ALayer * m_parent;
    virtual void action();
    virtual void shaderAction();
    virtual void release();

    AGeometric m_geometric;
    void initializeAll();
    APolygon polygon;
    virtual void OnTouchedPress(AVector2D pos);
    virtual void OnTouchedrelease(AVector2D pos);
    virtual void OnFocusLost();
private:
    void dumpTouchState();
    int touch_state;
    void computeMatrix();
    void computePolygon();
    QGLShaderProgram *m_program;
    GLuint m_texId = 0;
    ATexture m_texture;
    float mx_offset,my_offset;
    float m_angle;
    GLfloat m_alpha;
    AColor m_color;
    bool isDeath = false;
    bool isNeedRealTime = false;
    void bindDefalutProgram();
    void deleteThis();
    float m_leftTopX = 0;
    float m_leftTopY = 0;
    float m_rightTopX = 0;
    float m_rightTopY = 0;
    float m_leftBottonX = 0;
    float m_leftBottonY = 0;
    float m_rightBottonX = 0;
    float m_rightBottonY = 0;
    bool m_isHide = false;
};
}


#endif // ASPRITE_H
