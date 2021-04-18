#ifndef HEROESFACTORY_H
#define HEROESFACTORY_H

#include "heros.h"



typedef Heros *(*CreateHeroeFn)();

class HeroesFactory
{
public:

    HeroesFactory();
    static QMap<QString, CreateHeroeFn> registeredFunctions;

    void Register(QString type, CreateHeroeFn fn);
    void Info();
    void Resistance();
    int NbHeroes();

    Heros *Create(QString type, QString name);

};

#endif // HEROESFACTORY_H
