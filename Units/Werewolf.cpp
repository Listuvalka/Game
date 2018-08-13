#include "Werewolf.h"


Werewolf::Werewolf():
    Unit(WEREWOLF, new State(120, 30), "Unit") {
	this->ability = new WerewolfAbility(this);
}
	Werewolf::~Werewolf() {}


