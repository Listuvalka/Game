#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../State/State.h"
#include "../Ability/Ability.h"
// #include "../State/IObserveble.h"
#include "../Group.cpp"



class Ability;
// class Necromancer;

class Unit {
protected:
    enName name;
    State* state;
    Ability* ability;
    const char* type;

public:
    Unit(enName name, State* state, const char* type);
    virtual ~Unit();
    
    virtual void delBook();

    void ensureIsAlive();
    void setName(enName name);
    void setState(State* newState);
    void setAbility(Ability* newAbility);
    
    // void setObserver(Unit* observer);
    // void notify(int hp);

    int getDamage() const;
    int getHitPoint() const;
    int getHitPointLimit() const;
    enName getName() const;

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
