#include "PriestAbility.h"

PriestAbility::PriestAbility(Unit* owner): Ability(owner) {};
PriestAbility::~PriestAbility() {};

void PriestAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    if ( enemy->getName() == 4 || enemy->getName() == 11 ) {
        enemy->takeDamage(this->owner->getDamage() * 2); 
// std::cout << "Vampire->getHitPoint() " << enemy->getHitPoint() << '\n'; 
    } else {
        enemy->takeDamage(this->owner->getDamage());
    }
    enemy->counterAttack(this->owner);
}
void PriestAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    if ( enemy->getName() == 4 || enemy->getName() == 11 ) {
        enemy->takeDamage(this->owner->getDamage());
 // std::cout << "Vampire->getHitPoint() " << enemy->getHitPoint() << '\n';        
    } else {
        enemy->takeDamage(this->owner->getDamage() / 2);
    }
}