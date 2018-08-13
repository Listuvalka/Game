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
	// std::cout << "Priest->takeDamage() " << enemy->getHitPoint() << '\n';
	enemy->counterAttack(this->owner);
}

void VampireAbility::counterAttack(Unit* enemy) {
	int enemyHP = enemy->getHitPoint();
    
    // std::cout << "Vampire->takeDamage() " << owner->getHitPoint() << '\n';
	this->owner->ensureIsAlive();
	enemy->takeDamage(this->owner->getDamage()/2);
// std::cout << "Priest->takeDamage() " << enemy->getHitPoint() << '\n';
	if ( enemyHP < this->owner->getDamage()/2 ) {
		this->owner->addHitPoint(enemyHP);

	} else {
		this->owner->addHitPoint(this->owner->getDamage()/2);
		// std::cout << "Vampire->addHitPoint(this->owner->getDamage()/2) " << owner->getHitPoint() << '\n';	
	}

}
void VampireAbility::useAbility(Unit* target) {

    std::string sp = "SpellCaster";
	if ( target->getName() != 4 && target->getName() != 6 && target->getName() != 5 ) {
	    // Ability* tmpAbility = new VampireAbility(target);
	    target->setAbility(new VampireAbility(target));
	    
	    if ( target->getType() == sp) {
	    	// std::cout << "target->getType() " << target->getType() << '\n';
	    	target->delBook();
	    }
	    target->setState(new State(150, 20)); 
	    // std::cout << "target->getName() " << target->getName() << '\n'; 
        target->setName(VAMPIRE);
	}
}


