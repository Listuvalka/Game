#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H


#include <iostream>
#include <map>
#include "../Spell/Spell.h"
// #include "../Spell/HitSpell/Fireball.h"
// #include "../Spell/HitSpell/Lightning.h"
// #include "../Spell/Heal.h"

enum enSp {
    FIREBALL = 1,
    LIGHTINING,
    HEAL
};

class SpellBook {
protected:
    Spell* spell;
    std::map<enSp, Spell*>* m_spellBook;
    enSp key;
public:
    SpellBook(Spell* spell, enSp key);
    virtual ~SpellBook();
    
    const char* getSpellName() const;

    void addSpell(Spell* newSpell, enSp key);
    void chooseSpell();
    void cast(Unit* target, enSp key);


};
#endif // SPELL_BOOK_H
