#ifndef LIGHTNING_H
#define LIGHTNING_H

#include <iostream>
#include "../../Spell/Hit.h"

class Lightning: public Hit {
public:
    Lightning(SpellCaster* owner);
    virtual ~Lightning();
};

#endif // LIGHTNING_H