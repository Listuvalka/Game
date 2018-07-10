#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../Units/Unit.h"
#include "../Units/SpellCaster.h"
#include "../Group.cpp"

class SpellCaster;

class Spell {
protected:
    SpellCaster* owner;
	int actionPoint;
	int cost;
    enSp spellName;
public:
	Spell(SpellCaster* owner, enSp spellName, int actionPoint, int cost);
	virtual ~Spell();

	int getActionPoint() const;
	int getCost() const;
    enSp getSpellName() const;
    
	virtual void action(Unit *target) = 0;
};

#endif// SPELL_H
