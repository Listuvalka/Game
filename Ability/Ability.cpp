#include "Ability.h"

Ability::Ability(Unit* owner): owner(owner) {}

Ability::~Ability() {}

void Ability::delBook() {
    return;
}
void Ability::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
}
void Ability::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / 2);
}

void Ability::useAbility(Unit* target) {
    return;
}

void Ability::useAbilityTR() {
    return;
}

