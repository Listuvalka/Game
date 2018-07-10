#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>

#include "../Units/SpellCaster.h"
#include "../Spell/HitSpell/Fireball.h"
#include "../Spell/HitSpell/Lightning.h"
#include "../Spell/Heal.h"

class Wizard: public SpellCaster {
public:
    Wizard();
    virtual ~Wizard();

};

#endif// WIZARD_H