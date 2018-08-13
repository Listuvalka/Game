#ifndef HIT_H
#define HIT_H

#include <iostream>
#include "../Spell/Spell.h"




class Hit: public Spell {

public:
    Hit(SpellCaster* owner, enSp spellName, int actionPoint, int cost);
    virtual ~Hit();
    
    virtual void action(Unit *target);
};

#endif //HIT_H