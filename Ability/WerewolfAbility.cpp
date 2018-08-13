#include "WerewolfAbility.h"

WerewolfAbility::WerewolfAbility(Unit* owner): Ability(owner) {}
WerewolfAbility::~WerewolfAbility() {}
    
void WerewolfAbility::attack(Unit* enemy) {
	this->Ability::attack(enemy);
}

void WerewolfAbility::useAbilityTR() {
    this->owner->ensureIsAlive();

    if ( this->owner->getName() != 6 ) {
        this->owner->setName(WOLF);
        this->owner->setState(new WolfState());
        }
}
void WerewolfAbility::useAbility(Unit *target) {
    std::string sp = "SpellCaster";

    if ( target->getName() != 4 && target->getName() != 5 && target->getName() != 6 ) {
        target->setAbility(new WerewolfAbility(target));
        if ( target->getType() == sp) {
            target->delBook();
        }
        
        target->setState(new State(120, 30)); 
// std::cout << "target->getDamage() = " << target->getDamage() << std::endl;
// std::cout << "target->getHitPoint() = " << target->getHitPoint() << std::endl;
        target->setName(WEREWOLF);  
// std::cout << "target->getName() = " << target->getName() << std::endl; 
    }
}





