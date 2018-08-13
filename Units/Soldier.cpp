#include "Soldier.h"

Soldier::Soldier():
    Unit(SOLDIER, new State(100, 10), "Unit") {
	this->ability = new DefAbility(this);
}

Soldier::~Soldier() {}

