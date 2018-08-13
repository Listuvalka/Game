#pragma once
#ifndef I_OBSERVER_H
#define I_OBSERVER_H

class IObserver {
public:
    virtual void updeteHP(int hp) = 0;
};

#endif // I_OBSERVER_H