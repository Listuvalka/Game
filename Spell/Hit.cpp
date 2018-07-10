#include "Hit.h"

Hit::Hit(SpellCaster* owner, enSp spellName, int actionPoint, int cost): Spell(owner, spellName, actionPoint, cost) {}
Hit::~Hit() {}

void Hit::action(Unit *target) {
    std::string wizard = "Wizard";
    std::string healer = "Healer";
    
    if ( this->owner->getName() != wizard && this->owner->getName() != healer ) {
        target->takeMagDamage(this->getActionPoint());
    } else {
        target->takeMagDamage(this->getActionPoint()/2);
    }
}