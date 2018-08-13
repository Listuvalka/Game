#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Exception.cpp"


class State {
protected:
    int hitPoint;
    int hitPointLimit;
    int damage;
    
    void defDamage(int dmg);
public:
    State(int hitPoint, int damage);
    virtual ~State();

    void ensureIsAlive();
    int getDamage() const;
    int getHitPoint() const;
    int getHitPointLimit() const;
    
    void addHitPoint(int hp);
    virtual void takeDamage(int dmg);
    virtual void takeMagDamage(int dmg);
};

#endif // STATE_H
