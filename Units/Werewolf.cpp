#include "Werewolf.h"


Werewolf::Werewolf():
    Unit(new State("Werewolf", 120, 30), "Unit") {
	this->ability = new WerewolfAbility(this);
}
	Werewolf::~Werewolf() {}


