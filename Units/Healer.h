#ifndef HEALER_H
#define HEALER_H

#include <iostream>

#include "../Units/SpellCaster.h"
#include "../Spell/HitSpell/Fireball.h"
#include "../Spell/HitSpell/Lightning.h"
#include "../Spell/Heal.h"

class Healer: public SpellCaster {
public:
    Healer();
    virtual ~Healer();

};

#endif// HEALER_H