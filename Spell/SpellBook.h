#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H


#include <iostream>
#include <map>
#include "Spell.h"
#include "../Group.cpp"

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
