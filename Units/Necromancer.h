#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>

#include "../Units/SpellCaster.h"
#include "../State/IObserver.h"


class Necromancer: public SpellCaster, IObserver {
public:
    Necromancer();
    virtual ~Necromancer();

    void setObserver(Unit* observer);

    void updeteHP(int hp);
};

#endif // NECROMANCER_H