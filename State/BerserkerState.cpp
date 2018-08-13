#include "BerserkerState.h"

BerserkerState::BerserkerState(int hitPoint, int damage): State(hitPoint, damage) {}
BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(int dmg) {
    throw BerserkerException();
}

