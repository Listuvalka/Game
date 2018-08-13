#include "Healer.h"

Healer::Healer(): SpellCaster(HEALER, 80, 10, 80, "SpellCaster") {
    addSpell(new Fireball(this), FIREBALL);
    addSpell(new Lightning(this), LIGHTINING);
    addSpell(new Heal(this), HEAL);
}
Healer::~Healer() {}