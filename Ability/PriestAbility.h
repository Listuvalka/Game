#ifndef PRIEST_ABILITY_H
#define PRIEST_ABILITY_H

#include <iostream>
#include "Ability.h"
#include "../Exception.cpp"

class PriestAbility: public Ability {
public:
    PriestAbility(Unit* owner);
    virtual ~PriestAbility();

    virtual void attack(Unit* enemy);
    virtual void counterAttack(Unit* enemy);
};

#endif //PRIEST_ABILITY_H