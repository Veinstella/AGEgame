#ifndef AGE_SOUND_H
#define AGE_SOUND_H

#include <QtMultimedia/QSoundEffect>
#include <QtMultimedia>

#include <QString>

class ASound
{
public:
    ASound(QString audName);
    void play();
    void stop();
    QString getObjName() const;
    void setObjName(const QString &value);

    QString getAudName() const;
    void setAudName(const QString &value);

    QSoundEffect *getMusic() const;
    void setMusic(QSoundEffect *value);

    bool getLoopORnot() const;
    void setLoopORnot(bool value);

    qreal getVolume() const;
    void setVolume(qreal volume);

private:
    QSoundEffect * music;
    QString objName;
    QString audName;
    bool loopORnot;
    qreal Volume;
};

#endif // AGE_SOUND_H
