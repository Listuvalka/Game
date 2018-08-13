#include "Berserker.h"

Berserker::Berserker(): Unit(BERSERKER, new BerserkerState(110, 30), "Unit") {
	this->ability = new DefAbility(this);
}

Berserker::~Berserker() {};

