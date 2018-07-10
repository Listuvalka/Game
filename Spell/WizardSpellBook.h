#ifndef WIZARD_SPELL_BOOK
#define WIZARD_SPELL_BOOK

#include <iostream>
#include "SpellBook.h"
#include "../Spell/HitSpell/Fireball.h"
#include "../Spell/HitSpell/Lightning.h"
#include "../Spell/Heal.h"


class WizardSpellBook: public SpellBook {
public:
    WizardSpellBook();
    virtual ~WizardSpellBook();
};

#endif //WIZARD_MAG_ABILITY