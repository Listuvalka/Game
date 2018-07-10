#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include <string>
#include "Unit.h"
#include "../Ability/VampireAbility.h"
#include "../State/State.h"

class Vampire: public Unit {
    public:
	    Vampire();
	    virtual ~Vampire();

	    // void infect(Unit *target);

};
#endif // VAMPIRE_H
