#include "eventfactory.h"
#include "heros.h"
#include <QDebug>



QMap<QString, CreateEventFn> EventFactory::registeredFunctionsEvent;

EventFactory::EventFactory()
{

}

void EventFactory::Register(QString type, CreateEventFn fn)
{
    qDebug()  << "register" << type;
    registeredFunctionsEvent[type] = fn;
}

void EventFactory::setDmg()
{
    for (auto event : qAsConst(Event::createdEvent)) {
           event->setDmg();
    }
}

void EventFactory::Attack(int i)
{
    qDebug() << "Attaque Ennemis: " ;

    Event::createdEvent.at(i)->Info();

    for (auto hero : qAsConst(Heros::created)) {
        QString resi = hero->resistance();
        if (resi == "Physique") {
            int dmg = hero->resistancePts() - Event::createdEvent.at(i)->getDmg_phy();
            hero->receiveDmgs(dmg);
        }
        else if (resi == "Magique") {
            int dmg = hero->resistancePts() - Event::createdEvent.at(i)->getDmg_mag();
            hero->receiveDmgs(dmg);
        }
        else if (resi == "Piege") {
            int dmg = hero->resistancePts() - Event::createdEvent.at(i)->getDmg_pieges();
            hero->receiveDmgs(dmg);
        }
    }

}

Event *EventFactory::Create(QString type)
{
    Event *e;
    CreateEventFn fn = registeredFunctionsEvent[type];
    if (fn != nullptr) {
        e = fn();
        e->setType(type);
        Event::createdEvent.push_back(e);
        return e;
    }
    return nullptr;
}
