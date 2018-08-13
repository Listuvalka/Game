#include "Vampire.h"

Vampire::Vampire(): Unit(VAMPIRE, new State(150, 20), "Unit") {
	this->ability = new VampireAbility(this);
}
Vampire::~Vampire() {}

// void Vampire::infect(Unit *target) {
//     this->ability->infect(target);
// }
