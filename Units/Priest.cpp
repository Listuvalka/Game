#include "Priest.h"


Priest::Priest(): SpellCaster(PRIEST, 110, 20, 100, "SpellCaster") {
    this->ability = new PriestAbility(this);
    addSpell(new Fireball(this), FIREBALL);
    addSpell(new Lightning(this), LIGHTINING);
    addSpell(new Heal(this), HEAL);
}
Priest::~Priest() {}