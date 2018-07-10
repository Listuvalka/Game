#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Unit.h"
#include "../Ability/RogueAbility.h"

class Rogue:public Unit {
public:
	Rogue();
	virtual ~Rogue();

};

#endif// ROGUE_H
