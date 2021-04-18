#include "Heros.h"

#include <QVector>


QVector<Heros *> Heros::created;

QString Heros::type() const
{
    return m_type;
}

void Heros::setType(const QString &type)
{
    m_type = type;
}

QString Heros::name() const
{
    return m_name;
}

void Heros::setName(const QString &name)
{
    m_name = name;
}

void Heros::Info()
{
    qDebug() << type() << name() << getPdv();
}

void Heros::receiveDmgs(int dmg_pts)
{

    if ( (getPdv() - dmg_pts ) <= 0){
        delete this;
    }else{
        setPdv(getPdv() - dmg_pts);
    }

}

int Heros::resistancePts() const
{
    return m_resistancePts;
}

void Heros::setResistancePts(int resistancePts)
{
    m_resistancePts = resistancePts;
}

int Heros::getPdv() const
{
    return pdv;
}

void Heros::setPdv(int value)
{
    pdv = value;
}

Heros::~Heros()
{
    qDebug() << "dead" << type();
    Heros::created.erase(std::remove(Heros::created.begin(), Heros::created.end(), this), Heros::created.end());
}

QString Heros::resistance() const
{
    return m_resistance;
}

void Heros::setResistance(const QString &resistance)
{
    m_resistance = resistance;
}

