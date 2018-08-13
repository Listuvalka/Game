#include "Warlock.h"

Warlock::Warlock(): SpellCaster(WARLOCK, 100, 15, 100, "SpellCaster") {}

Warlock:: ~Warlock() {}

Demon* Warlock::summonDemon() {
    this->magState->spendMana(45);
    
    Demon *newDemon = new Demon();
        
    return newDemon;
}
