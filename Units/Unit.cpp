#include "Unit.h"

Unit::Unit(State* state, const char* type): state(state) {
    this->type = type;
}

Unit::~Unit() {
    	delete (this->ability);
    	delete (this->state);
 }

void Unit::ensureIsAlive() {
	this->state->ensureIsAlive();
}
void Unit::setState(State* newState) {
	delete(this->state);
	this->state = newState;
}
void Unit::setAbility(Ability* newAbility) {
    delete(this->ability);
    this->ability = newAbility;
}

int Unit::getDamage() const {
	return this->state->getDamage();
}
int Unit::getHitPoint() const {
	return this->state->getHitPoint();
}
int Unit::getHitPointLimit() const {
	return this->state->getHitPointLimit();
}
const char* Unit::getName() const {
	return this->state->getName();
}

const char* Unit::getType() const {
    return this->type;
}

void Unit::addHitPoint(int hp) {
	this->state->addHitPoint(hp);
}
void Unit::takeDamage(int dmg) {
	this->state->takeDamage(dmg);
}
void Unit::takeMagDamage(int dmg) {
	this->state->takeMagDamage(dmg);
}

void Unit::attack(Unit* enemy) {
	this->ability->attack(enemy);
}
void Unit::counterAttack(Unit* enemy) {
	this->ability->counterAttack(enemy);
}
void Unit::useAbility(Unit* target) {
    this->ability->useAbility(target);
}
void Unit::useAbilityTR() {
    this->ability->useAbilityTR();
}