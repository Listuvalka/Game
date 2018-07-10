#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "../Spell/Spell.h"


class Heal: public Spell {
public:
    Heal(SpellCaster* owner);
    virtual ~Heal();
    virtual void action(Unit *target);
};

#endif //HEAL_H