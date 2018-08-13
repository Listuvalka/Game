#include "Necromancer.h"


Necromancer::Necromancer(): SpellCaster(NECROMANCER, 150, 15, 30, "SpellCaster") {

}
Necromancer::~Necromancer() {}

void Necromancer::setObserver(Unit* target) {
    target->state->setObserver(this);
}

void Necromancer::updeteHP(int hp) {
    this->state->addHitPoint(hp);
}

void Necromancer::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->getDamage());
    enemy->setObserver(this);
    enemy->counterAttack(this);

}

