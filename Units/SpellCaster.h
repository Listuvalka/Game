#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include <iostream>
#include <map>

#include "../Units/Unit.h"
#include "../Ability/DefAbility.h"
#include "../State/MagState.h"
#include "../Spell/Spell.h"
#include "../Group.cpp"


#include "../Exception.cpp"


class Spell;


class SpellCaster: public Unit {
protected:
	Spell* spell;
    std::map<enSp, Spell*>* m_spellBook;
    enSp key;
	MagState* magState;
public:
	SpellCaster(const char* name, int hitPoint, int damage, int mana, const char* type);
	virtual ~SpellCaster();
    
    enSp getSpellName() const;

	int getMana() const;
	int getManaLim() const;

	void addMana(int extra);
	void spendMana(int cost);

    void delBook();

	void addSpell(Spell* newSpell, enSp key);
	void chooseSpell();
	void cast(Unit* enemy, enSp key);

};

#endif //SPELL_CASTER_H
