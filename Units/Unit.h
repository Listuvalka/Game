#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../State/State.h"
#include "../Ability/Ability.h"


class Ability;

class Unit {
protected:
    State* state;
    Ability* ability;
    const char* type;

    
public:
    Unit(State* state, const char* type);
    virtual ~Unit();
    
    void ensureIsAlive();
    void setState(State* newState);
    void setAbility(Ability* newAbility);

    int getDamage() const;
    int getHitPoint() const;
    int getHitPointLimit() const;
    const char* getName() const;
    const char* getType() const;

    void addHitPoint(int hp);
    void takeDamage(int dmg);
    void takeMagDamage(int dmg);
    
    void attack (Unit* enemy);
    void counterAttack (Unit* enemy);

    void useAbility(Unit* target);
    void useAbilityTR();

};

#endif // UNIT_H
