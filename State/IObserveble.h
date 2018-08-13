#pragma once
#ifndef I_OBSERVEBLE_H
#define I_OBSERVEBLE_H

#include <iostream>
// #include <vector>
#include "../Units/Necromancer.h"

// class IObserveble {
// protected:
//     std::vector<Unit*> list;
// public:
//     virtual void addToList(Unit* flagged);
//     virtual void removeFromList(Unit* flagged);
//     virtual void notice(int hp);
// };


class IObserveble {
protected:
    Necromancer* observer;
public:
    virtual void setObserver(Necromancer* observer);
    virtual void notice(int hp);
};

#endif // I_OBSERVEBLE_H