#include "Rogue.h"

Rogue::Rogue(): Unit(new State("Rogue", 80, 15), "Unit") {
	this->ability = new RogueAbility(this);
}
Rogue::~Rogue(){}
