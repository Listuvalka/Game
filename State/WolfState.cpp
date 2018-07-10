#include "WolfState.h"


WolfState::WolfState(): State("Wolf", 150, 35) {}
WolfState::~WolfState() {}

void WolfState::takeDamage(int dmg) {
	this->State::takeDamage(dmg);
}
void WolfState::takeMagDamage(int dmg) {
    this->State::ensureIsAlive();
    dmg *= 1.5;
    
    if ( dmg  > this->hitPoint ) {
        this->hitPoint = 0;
        return;
    }
    this->hitPoint -= dmg;
}

