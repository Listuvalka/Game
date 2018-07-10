#include "WizardSpellBook.h"

WizardSpellBook::WizardSpellBook(): SpellBook(new Fireball(), FIREBALL) {
    addSpell(new Lightning(), LIGHTINING);
    addSpell(new Heal(), HEAL);
}
WizardSpellBook::~WizardSpellBook() {}