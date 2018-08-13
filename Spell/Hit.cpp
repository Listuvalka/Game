#include "Hit.h"

Hit::Hit(SpellCaster* owner, enSp spellName, int actionPoint, int cost): Spell(owner, spellName, actionPoint, cost) {}
Hit::~Hit() {}

void Hit::action(Unit *target) {
   
    if ( this->owner->getName() == 7 ) {
        
        // std::cout << " owner->getName() " << owner->getName() << std::endl;
        
        target->takeMagDamage(this->getActionPoint());
    } 
    else if ( this->owner->getName() == 9 ) {

        // std::cout << " owner->getName() " << owner->getName() << std::endl;
        
        if ( target->getName() == 4 || target->getName() == 11 ) {

            // std::cout << " target->getName() " << target->getName() << std::endl;

            target->takeMagDamage(this->getActionPoint() * 2);
        }
    else {
        target->takeMagDamage(this->getActionPoint()/2);
    }
    
    }
}