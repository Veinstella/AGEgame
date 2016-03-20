#include "../include/age_audio.h"
#include "QDebug"
namespace AGE2D{
AAudio::AAudio(QString audName)
{
    music = new QMediaPlayer;
    this->loopORnot = false;
    this->Volume = 50;
    this->mods = 0;
    this->audName = audName;
    this->music_length=0;
    audio();
}
AAudio::AAudio(QString audName,int mods)
{
    music = new QMediaPlayer;
    this->loopORnot = false;
    this->Volume = 50;
    this->mods = mods;
    this->audName = audName;
    this->music_length=0;
    audio();
}

void AAudio::audio()
{
    if(mods == 0)
    {

        /*QString pattern("(.*)/(.*.(mp3|mp4|ogg|flac|wav|ape|vqf|aac|mid|md|asf|m4a|aac|wma))");
        QFile f(this->audName);
        abcd = new ARegExp(pattern,audName);
        audName =abcd->getexitstr();
        delete abcd;
        f.copy(QDir::currentPath()+"/"+this->audName);*/
        //this->music->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/"+this->audName));
        this->music->setMedia(QUrl::fromLocalFile(this->audName));
        //this->music->setMedia(QUrl(QDir::currentPath()+"/"+this->audName));
    }
    else
    {
        this->music->setMedia(QUrl(this->audName));
    }
    //setListenerManager(new AEventMgr());
    //eventMgr()->addFrameListener();


}

void AAudio::beforeFrameRender()
{
    if(this->loopORnot==true)
    {
        this->music_length=this->music->duration();
        if(this->music->position()==this->music_length)
        {
            this->music->pause();
            this->music->setPosition(0);
            this->music->play();
        }
    }
}

void AAudio::play()
{
    music->stop();
    music->play();
}

void AAudio::stop()
{
    music->stop();
}

void AAudio::pause()
{
    music->pause();
}


AAudio::~AAudio()
{
    delete this->music;
}

QMediaPlayer *AAudio::getMusic() const
{
    return music;
}

void AAudio::setMusic(QMediaPlayer *value)
{
    music = value;
}

QString AAudio::getObjName() const
{
    return objName;
}

void AAudio::setObjName(const QString &value)
{
    objName = value;
}

QString AAudio::getAudName() const
{
    return audName;
}

void AAudio::setAudName(const QString &value)
{
    audName = value;
}

bool AAudio::getLoopORnot() const
{
    return loopORnot;
}

void AAudio::setLoopORnot(bool value)
{
    loopORnot = value;
}

int AAudio::getVolume() const
{
    return Volume;
}

void AAudio::setVolume(int value)
{
    Volume = value;
    this->music->setVolume(this->Volume);
}

int AAudio::getMods() const
{
    return mods;
}

void AAudio::setMods(int value)
{
    mods = value;
}
}
