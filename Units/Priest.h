#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>

#include "../Units/SpellCaster.h"
#include "../Ability/PriestAbility.h"
#include "../Spell/HitSpell/Fireball.h"
#include "../Spell/HitSpell/Lightning.h"
#include "../Spell/Heal.h"

class Priest: public SpellCaster {
public:
    Priest();
    virtual ~Priest();
};

#endif //PRIEST_H