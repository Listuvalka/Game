#include "Lightning.h"

Lightning::Lightning(SpellCaster* owner): Hit(owner, LIGHTINING, 10, 5) {}
Lightning::~Lightning() {}