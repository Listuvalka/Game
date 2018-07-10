#include "WerewolfAbility.h"

WerewolfAbility::WerewolfAbility(Unit* owner): Ability(owner) {}
WerewolfAbility::~WerewolfAbility() {}
    
void WerewolfAbility::attack(Unit* enemy) {
	this->Ability::attack(enemy);
}

void WerewolfAbility::useAbilityTR() {
	std::string wolf = "Wolf";

    this->owner->ensureIsAlive();

    if (this->owner->getName() != wolf.c_str()) {
        this->owner->setAbility(new DefAbility(owner));
        this->owner->setState(new WolfState());
    }
}
void WerewolfAbility::useAbility(Unit *target) {
std::string vampire = "Vampire";
    std::string wolf = "Wolf";
    std::string werewolf = "Werewolf";

    if ( target->getName() != vampire && target->getName() != wolf && target->getName() != werewolf ) {
        Ability* tmpAbility = new WerewolfAbility(target);
        target->setAbility(tmpAbility);
        target->setState(new State("Werewolf", 120, 30));    
    }
}





