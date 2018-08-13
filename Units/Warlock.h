#ifndef WERLOC_H
#define WERLOC_H

#include <iostream>

#include "../Units/SpellCaster.h"
// #include "../Ability/DefAbility.h"
#include "../Units/Demon.h"

class Warlock: public SpellCaster {
public:
    Warlock();
    virtual ~Warlock();

    Demon* summonDemon();
};

#endif //WERLOC_H