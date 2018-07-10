#include "DefAbility.h"

DefAbility::DefAbility(Unit* owner): Ability(owner) {}
DefAbility::~DefAbility() {}

void DefAbility::attack(Unit* enemy) {
    this->Ability::attack(enemy);
}
