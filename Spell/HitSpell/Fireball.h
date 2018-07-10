#ifndef FIREBALL_H
#define FIREBALL_H

#include <iostream>
// #include "../../Spell/Spell.h"
#include "../../Spell/Hit.h"



class Fireball: public Hit {
public:
    Fireball(SpellCaster* owner);
    virtual ~Fireball();
};

#endif // FIREBALL_H