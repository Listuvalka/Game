#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include "../Units/Unit.h"
#include "../Exception.cpp"
#include "../Group.cpp"



class Unit;

class Ability {
protected:
    Unit* owner;

public:
    Ability(Unit* owner);
    virtual ~Ability();

    virtual void delBook();

    virtual void attack(Unit* enemy) = 0;
    virtual void counterAttack(Unit* enemy);

    virtual void useAbility(Unit* target);
    virtual void useAbilityTR();

};

#endif // ABILITY_H 
