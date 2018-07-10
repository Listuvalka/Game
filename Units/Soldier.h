#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"
#include "../Ability/DefAbility.h"

class Soldier: public Unit {
    public:
	    Soldier();
	    virtual ~Soldier();
};
#endif /* SOLDIER_H */
