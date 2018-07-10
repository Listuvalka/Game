#ifndef WOLF_STATE_H
#define WOLF_STATE_H

#include <iostream>
#include "State.h"
#include "../Exception.cpp"

class WolfState: public State {
public:
	WolfState();
	~WolfState();

    virtual void takeDamage(int dmg);
    virtual void takeMagDamage(int dmg);
};



#endif // WOLF_STATE_H
