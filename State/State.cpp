#include "State.h"

State::State(int hitPoint, int damage) {
    this->hitPoint = hitPoint;
    this->hitPointLimit = hitPoint;
    this->damage = damage;
}
State:: ~State() {}



void State::ensureIsAlive() {
    if ( this->hitPoint == 0 ) {
        throw OutOfHPException();
    }
}
int State::getDamage() const {
    return this->damage;
}
int State::getHitPoint() const {
    return this->hitPoint;
}
int State::getHitPointLimit() const {
    return this->hitPointLimit;
}

void State::addHitPoint(int hp) {
    this->ensureIsAlive();

    int tmpHitPoint = this->hitPoint + hp;
    
    if ( tmpHitPoint < this->hitPointLimit ) {
        this->hitPoint = tmpHitPoint;
    } else {
        this->hitPoint = this->hitPointLimit;
    }
}

void State::defDamage(int dmg) {
     this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
        return;
    }
    this->hitPoint -= dmg;
}
void State::takeMagDamage(int dmg) {
    this->defDamage(dmg);
}
void State::takeDamage(int dmg) {
    this->defDamage(dmg);
}
