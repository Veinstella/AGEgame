#include "../include/age_timer.h"

namespace AGE2D {

ATimer::ATimer(int interval, bool isSingleShot)
{
    this->timer=new QTimer(this);
    this->func=NULL;
    this->interval=interval;
    this->isSingleShot=isSingleShot;
    connect(this->timer,SIGNAL(timeout()),this,SLOT(fuck()));
}

void ATimer::start()
{
    this->timer->start(this->interval);
    this->timer->setSingleShot(isSingleShot);
}

void ATimer::changeInterval(int interval)
{
    this->interval=interval;
    this->timer->setInterval(this->interval);
}

int ATimer::getInterval()
{
    return this->interval;
}

void ATimer::fuck()
{
    if(this->func)
        this->func();
}

void ATimer::setSingleShot(bool isSingleShot)
{
    this->timer->setSingleShot(isSingleShot);
    this->isSingleShot=isSingleShot;
}

void ATimer::setAction(void (*func)())
{
    this->func=func;
}

bool ATimer::getIsSingleShot()
{
    return this->isSingleShot;
}

} // namespace AGE2D
