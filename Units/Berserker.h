#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Unit.h"
#include "../Ability/DefAbility.h"
#include "../State/BerserkerState.h"

class Berserker : public Unit {
    public:
	    Berserker();
	    virtual ~Berserker();

};
#endif // BERSERKER_H
