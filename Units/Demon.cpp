#include "Demon.h"

Demon::Demon():
    Unit(DEMON, new State(80, 30), "Unit") {
	this->ability = new DefAbility(this);
}

Demon::~Demon() {}

