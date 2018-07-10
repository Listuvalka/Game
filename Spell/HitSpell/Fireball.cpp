#include "Fireball.h"

Fireball::Fireball(SpellCaster* owner): Hit(new Spell(owner, FIREBALL, 15, 10)) {}
Fireball::~Fireball() {}
