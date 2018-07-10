#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* owner): Ability(owner) {}
VampireAbility::~VampireAbility() {}

void VampireAbility::attack(Unit* enemy) {
	int enemyHP = enemy->getHitPoint();

	this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());

	if ( enemyHP < this->owner->getDamage()/2 ) {
		this->owner->addHitPoint(this->owner->getDamage()/2);
	} else {
		this->owner->addHitPoint(this->owner->getDamage()/2);
	}
	enemy->counterAttack(this->owner);
}

void VampireAbility::counterAttack(Unit* enemy) {
	int enemyHP = enemy->getHitPoint();

	this->owner->ensureIsAlive();
	enemy->takeDamage(this->owner->getDamage()/2);

	if ( enemyHP < this->owner->getDamage()/2 ) {
		this->owner->addHitPoint(enemyHP);
	} else {
		this->owner->addHitPoint(this->owner->getDamage()/2);
	}

}
void VampireAbility::useAbility(Unit* target) {
    std::string vampire = "Vampire";
	std::string wolf = "Wolf";
	std::string werewolf = "Werewolf";
    std::string sp = "SpellCaster";

	if ( target->getName() != vampire && target->getName() != wolf && target->getName() != werewolf) {
	    Ability* tmpAbility = new VampireAbility(target);
	    target->setAbility(tmpAbility);
	    
	    // if ( target->getType() == sp) {
	    // 	target->SpellCaster::delBook();
	    // }
	    target->setState(new State("Vampire", 150, 20));   
	}
}

// void VampireAbility::infect(Unit *target) {
	
// }

