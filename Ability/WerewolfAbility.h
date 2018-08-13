#ifndef WEREWOLF_ABILITY_H
#define WEREWOLF_ABILITY_H

#include <iostream>
#include <string>
#include "../Exception.cpp"
#include "../Ability/Ability.h"
#include "../Ability/DefAbility.h"
#include "../State/WolfState.h"


class WerewolfAbility: public Ability {
public:
	WerewolfAbility(Unit* owner);
    virtual ~WerewolfAbility();
    
    virtual void attack(Unit* enemy);

    virtual void useAbilityTR();
    virtual void useAbility(Unit* owner);

};

#endif // WEREWOLF_ABILITY_H
