#include "Rogue.h"

Rogue::Rogue(): Unit(ROGUE, new State(80, 15), "Unit") {
	this->ability = new RogueAbility(this);
}
Rogue::~Rogue(){}
