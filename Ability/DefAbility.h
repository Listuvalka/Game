#ifndef DEF_ABILITY_H
#define DEF_ABILITY_H

#include "Ability.h"

class Unit;

class DefAbility: public Ability {
public:
    DefAbility(Unit* owner);
    virtual ~DefAbility();
    
    virtual void attack(Unit* enemy);
};

#endif /* DEF_ABILITY_H */
