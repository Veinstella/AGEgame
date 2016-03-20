#ifndef AGE_AUDIO_H
#define AGE_AUDIO_H
#include <QString>
#include <QtMultimedia/qmediaplayer.h>
#include <QtMultimedia/qmediaplaylist.h>
#include <QDir>
#include "../include/age_regexp.h"
#include "../include/age_framelistener.h"
namespace AGE2D{
class AAudio : public AFrameListener
{
protected:
    QFile f;
    QMediaPlayer * music;
    QString objName;
    QString audName;
    ARegExp *abcd;
    bool loopORnot;
    int Volume;
    int mods;
    qint64 music_length;

public:
    AAudio(QString audName);
    AAudio(QString audName,int mods);
    void audio();
    void play();
    void stop();
    void pause();
    virtual void beforeFrameRender();;
    ~AAudio();
    QMediaPlayer *getMusic() const;
    void setMusic(QMediaPlayer *value);
    QString getObjName() const;
    void setObjName(const QString &value);
    QString getAudName() const;
    void setAudName(const QString &value);
    bool getLoopORnot() const;
    void setLoopORnot(bool value);
    int getVolume() const;
    void setVolume(int value);
    int getMods() const;
    void setMods(int value);
};
}

#endif // AGE_AUDIO_H
