#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#include <iostream>
#include <string>
#include "Ability.h"
#include "../Units/Unit.h"
#include "../Units/SpellCaster.h"
#include "../Exception.cpp"


class VampireAbility: public Ability {
// private:
//     void infect(Unit* target);

public:
	VampireAbility(Unit* owner);
    virtual ~VampireAbility();
    
    virtual void attack(Unit* enemy);
    virtual void counterAttack(Unit* enemy);
    
    void useAbility(Unit* target);
    
    

};

#endif // VAMPIRE_ABILITY_H
