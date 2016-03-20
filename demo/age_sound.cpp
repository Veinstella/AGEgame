#include "age_sound.h"

ASound::ASound(QString audName)
{
    this->music =  new QSoundEffect();
    this->audName=audName;
    this->loopORnot = false;
    this->Volume =0.5;
    music->setSource(QUrl::fromLocalFile(audName));
    music->setVolume(Volume);

}

void ASound::play()
{
    music->play();
}

void ASound::stop()
{
    music->stop();
}
QString ASound::getObjName() const
{
    return objName;
}

void ASound::setObjName(const QString &value)
{
    objName = value;
}
QString ASound::getAudName() const
{
    return audName;
}

void ASound::setAudName(const QString &value)
{
    audName = value;
}
QSoundEffect *ASound::getMusic() const
{
    return music;
}

void ASound::setMusic(QSoundEffect *value)
{
    music = value;
}
bool ASound::getLoopORnot() const
{
    return loopORnot;
}

void ASound::setLoopORnot(bool value)
{
    loopORnot = value;
    if(loopORnot==true)
        this->music->setLoopCount(QSoundEffect::Infinite);
    else this->music->setLoopCount(false);

}
qreal ASound::getVolume() const
{
    return Volume;
}

void ASound::setVolume(qreal value)
{
    Volume = value;
    this->music->setVolume(Volume);
}







