#include "../include/age_regexp.h"
namespace AGE2D{
QString ARegExp::getPattern() const
{
    return pattern;
}

void ARegExp::setPattern(const QString &value)
{
    pattern = value;
}

QString ARegExp::getStr() const
{
    return str;
}

void ARegExp::setStr(const QString &value)
{
    str = value;
}
ARegExp::ARegExp(QString pattern,QString str)
{
    this->pattern=pattern;
    this->str=str;
}

QString ARegExp::getexitstr()
{
    QRegExp rx(this->pattern);
    int pos = this->str.indexOf(rx);
    if ( pos >= 0 )
    {
        return rx.cap(2);
    }
}
}
