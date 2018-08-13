#include "Unit.h"

Unit::Unit(enName name, State* state, const char* type): state(state) {
    this->name = name;
    this->type = type;
}

Unit::~Unit() {
    	delete (this->ability);
    	delete (this->state);
 }

//  void Unit::setObserver(Unit* newObserver) {
//     if ( observer == NULL ) {
//         this->observer = newObserver;
//     } 
// }

// void Unit::notify(int hp) {
//     this->observer->ensureIsAlive();
//     this->observer->notice(hp);
// }

void Unit::delBook() {
    this->ability->delBook();
}

void Unit::ensureIsAlive() {
	this->state->ensureIsAlive();
}

void Unit::setName(enName name) {
    this->name = name;
}
void Unit::setState(State* newState) {
	delete(this->state);
	this->state = newState;
    // std::cout << "State initialathed in Unit getDamage() = " << this->state->getDamage() << std::endl;
    // std::cout << "State initialathed in Unit getHitPoint() = " << this->state->getHitPoint() << std::endl;
}
void Unit::setAbility(Ability* newAbility) {
    delete(this->ability);
    this->ability = newAbility;
}

// void Unit::setObserver(Unit* observer) {
//     this->state->setObserver(observer);
// }
// void Unit::notice(int hp) {
//     this->state->notice(int hp);
// }

int Unit::getDamage() const {
	return this->state->getDamage();
}
int Unit::getHitPoint() const {
	return this->state->getHitPoint();
}
int Unit::getHitPointLimit() const {
	return this->state->getHitPointLimit();
}
enName Unit::getName() const {
	return this->name;
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