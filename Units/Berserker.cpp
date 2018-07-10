#include "Berserker.h"

Berserker::Berserker(): Unit(new BerserkerState("Berserker", 110, 30), "Unit") {
	this->ability = new DefAbility(this);
}

Berserker::~Berserker() {};

