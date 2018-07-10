#include "BerserkerState.h"

BerserkerState::BerserkerState(const char* name, int hitPoint, int damage): State(name, hitPoint, damage) {}
BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(int dmg) {
    throw BerserkerException();
}

