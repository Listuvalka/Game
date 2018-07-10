#ifndef ROGUE_ABILITY_H
#define ROGUE_ABILITY_H

#include <iostream>
#include "Ability.h"
#include "../Exception.cpp"

class RogueAbility: public Ability {
public:
	RogueAbility (Unit* owner);
	virtual ~RogueAbility();

	virtual void attack (Unit* enemy);
};

#endif //ROGUE_ABILITY_H
