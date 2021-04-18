#include "event.h"


#include <QVector>


QVector<Event *> Event::createdEvent;

QString Event::type() const
{
    return m_type;
}

void Event::setType(const QString &type)
{
    m_type = type;
}

void Event::Info()
{
    qDebug() << type() ;
}

int Event::getDmg_phy() const
{
    return dmg_phy;
}

void Event::setDmg_phy(int value)
{
    dmg_phy = value;
}

int Event::getDmg_mag() const
{
    return dmg_mag;
}

void Event::setDmg_mag(int value)
{
    dmg_mag = value;
}

int Event::getDmg_pieges() const
{
    return dmg_pieges;
}

void Event::setDmg_pieges(int value)
{
    dmg_pieges = value;
}
