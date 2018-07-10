#include "Spell.h"

Spell::Spell(SpellCaster* owner, enSp* spellName, int actionPoint, int cost): owner(owner) {
    this->spellName = spellName;
    this->actionPoint = actionPoint;
    this->cost = cost;
}
Spell::~Spell() {}

int Spell::getActionPoint() const {
	return this->actionPoint;
}

int Spell::getCost() const {
	return this->cost;
}

enSp* Spell::getSpellName() const {
    return this->spellName;
}