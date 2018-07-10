#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "State.h"
#include "../Exception.cpp"

class BerserkerState: public State {
public:
	BerserkerState(const char* name, int hitPoint, int damage);
	virtual ~BerserkerState();

    void takeMagDamage(int dmg);
};

#endif // BERSERKER_STATE_H
