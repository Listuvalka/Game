#include "Wizard.h"

Wizard::Wizard(): SpellCaster("Wizard", 100, 5, 100, "SpellCaster") {
    addSpell(new Fireball(this), FIREBALL);
    addSpell(new Lightning(this), LIGHTINING);
    addSpell(new Heal(this), HEAL);
}
Wizard::~Wizard() {}