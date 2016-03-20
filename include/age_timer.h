#ifndef AGE2D_AGE_TIMER_H
#define AGE2D_AGE_TIMER_H
#include <qtimer.h>
namespace AGE2D {

class ATimer:public QObject
{
    Q_OBJECT
public:
    ATimer(int interval=1000,bool isSingleShot=false);
    void start();
    void changeInterval(int interval);
    int getInterval();

    void setSingleShot(bool isSingleShot);
    void setAction(void(*func)(void));
    bool getIsSingleShot();

private:
    QTimer * timer;
    int interval;
    void (*func)(void);
    bool isSingleShot;
private slots:
    void fuck();
};

} // namespace AGE2D

#endif // AGE2D_AGE_TIMER_H
