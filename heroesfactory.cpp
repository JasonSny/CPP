#include "heroesfactory.h"
#include <QDebug>

QMap<QString, CreateHeroeFn> HeroesFactory::registeredFunctions;

HeroesFactory::HeroesFactory()
{

}

void HeroesFactory::Register(QString type, CreateHeroeFn fn)
{
    qDebug()  << "Set Up : " << type;
    registeredFunctions[type] = fn;
}

void HeroesFactory::Info()
{
    for (auto heros : qAsConst(Heros::created)) {
       heros->Info();
    }
}

void HeroesFactory::Resistance()
{
    for (auto heros : qAsConst(Heros::created)) {
       heros->Resistance();
    }
}

int HeroesFactory::NbHeroes()
{
    return Heros::created.size();
}

Heros *HeroesFactory::Create(QString type, QString name)
{
    Heros *h;
    CreateHeroeFn fn = registeredFunctions[type];
    if (fn != nullptr) {
        h = fn();
        h->setType(type);
        h->setName(name);
        Heros::created.push_back(h);
        return h;
    }
    return nullptr;
}


