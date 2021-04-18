#include <QCoreApplication>
#include "heros.h"
#include "heroesfactory.h"
#include "event.h"
#include "eventfactory.h"
#include <QDebug>


void testFactory() {

    HeroesFactory herosFactory;
    herosFactory.Register("Warrior", &Warrior::create);
    herosFactory.Register("Wizzard", &Wizzard::create);
    herosFactory.Register("Rogue", &Rogue::create);

    Heros *Tilda = herosFactory.Create("Warrior", "Tilda");
    Heros *Potul = herosFactory.Create("Wizzard", "Potul");
    Heros *Xerza = herosFactory.Create("Rogue", "Xerza");


    herosFactory.Info();
    herosFactory.Resistance();

    EventFactory eventFactory;
    qDebug() << "\n";
    eventFactory.Register("~ Poison Arrow", &Daguette::create);
    eventFactory.Register("~ Sword Hit", &Epee::create);
    eventFactory.Register("~ Fireball", &BouleOnFire::create);
    eventFactory.Register("~ Fire Sword", &ArcAGele::create);

    Event *Daguette = eventFactory.Create("~ poison arrow");
    Event *Epee = eventFactory.Create("~ Swort Hit");
    Event *BouleOnFire = eventFactory.Create("~ Fireball");
    Event *ArcAGele = eventFactory.Create("~ Fire Sword");

    eventFactory.setDmg();
    int randomNumber;

    while (herosFactory.NbHeroes()>1) {

        randomNumber = (rand() % Event::createdEvent.size());
        qDebug() << "\n";
        eventFactory.Attack(randomNumber);
        herosFactory.Info();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testFactory();

    return a.exec();
}



