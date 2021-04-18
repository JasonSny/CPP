#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QVector>
#include <QDebug>

class Event
{
public:
    static QVector<Event *> createdEvent;

    QString type() const;

    int getDmg_phy() const;
    int getDmg_mag() const;
    int getDmg_pieges() const;

    void setType(const QString &type);
    void setDmg_phy(int value);
    void setDmg_mag(int value);
    void setDmg_pieges(int value);
    void Info();
    virtual void setDmg() =0;


private:
    QString m_type;
    int dmg_phy;
    int dmg_mag;
    int dmg_pieges;
};

template <typename T>
class TEvent : public Event
{
public:
    static Event *create(){
        return new T;
    };
};

class Daguette : public TEvent<Daguette> {
public:

    void setDmg() {
        setDmg_phy(1);
        setDmg_mag(1);
        setDmg_pieges(4);
    }
};

class Epee : public TEvent<Epee> {
public:

    void setDmg() {
        setDmg_phy(4);
        setDmg_mag(2);
        setDmg_pieges(0);
    }
};

class BouleOnFire : public TEvent<BouleOnFire> {
public:

    void setDmg() {
        setDmg_phy(3);
        setDmg_mag(4);
        setDmg_pieges(2);
    }
};

class ArcAGele : public TEvent<ArcAGele> {
public:

    void setDmg() {
        setDmg_phy(2);
        setDmg_mag(1);
        setDmg_pieges(3);
    }
};

#endif // EVENT_H
