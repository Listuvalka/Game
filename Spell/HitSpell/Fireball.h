#ifndef FIREBALL_H
#define FIREBALL_H

#include <iostream>
// #include "../../Spell/Spell.h"123
#include "../../Spell/Hit.h"



class Fireball: public Hit {
public:
    Fireball();
    virtual ~Fireball();
};

#endif // FIREBALL_H