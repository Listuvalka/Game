#include "Fireball.h"

Fireball::Fireball(SpellCaster* owner): Hit(owner, FIREBALL, 15, 10) {}
Fireball::~Fireball() {}
