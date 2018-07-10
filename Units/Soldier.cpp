#include "Soldier.h"

Soldier::Soldier():
    Unit(new State("Soldier", 100, 10), "Unit") {
	this->ability = new DefAbility(this);
}

Soldier::~Soldier() {}

