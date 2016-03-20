#ifndef AKEYLISTENER_H
#define AKEYLISTENER_H

#include <QKeyEvent>
namespace AGE2D{
class AKeyListener
{
public:
    friend class AEventMgr;
    void removeKeyListener();
	AKeyListener();
	virtual void onKeyRelease(QKeyEvent * event);
	virtual void onKeyPress (QKeyEvent *event);

private:
    bool keyislife = true;
};
}


#endif // AKEYLISTENER_H
