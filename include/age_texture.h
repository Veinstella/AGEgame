#ifndef ATEXTURE2D_H
#define ATEXTURE2D_H

#include <QGLFunctions>
#include <QImage>
#include <vector>

using namespace std;

namespace AGE2D
{
class ATexture : public QGLFunctions,public QImage
{
public:
    ATexture();
    ATexture(QString filename);
    void loadFile(QString filename);
    int width();
    int height();
    GLuint getTextureId();
private:
    GLuint m_texID;
    int m_width;
    int m_height;
    void bindTexture();
    QString m_fileName;
    vector <ATexture*> list;
};
}



#endif // ATEXTURE2D_H
