#include "Heal.h"

Heal::Heal(SpellCaster* owner): Spell(owner, HEAL, 30, 15) {};
Heal::~Heal() {};

void Heal::action(Unit *target) {
    std::string wizard = "Wizard";
    std::string healer = "Healer";

    if ( this->owner->getName()!= wizard && this->owner->getName()!= healer ) {
        target->addHitPoint(this->getActionPoint()/2);
    } else {
        target->addHitPoint(this->getActionPoint());
    }
}