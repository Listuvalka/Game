#include "catch.hpp"
#include "../Spell/HitSpell/Fireball.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Fireball spell class" ) {
    Spell *fireball = new Fireball();

    REQUIRE( fireball->getActionPoint() == 15 );
    REQUIRE( fireball->getCost() == 10 );
  
    SECTION( "Fireball::action test" ) {
        Soldier* soldier = new Soldier();

        REQUIRE( soldier->getHitPoint() == 100 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( soldier->getName() == "Soldier" );
        REQUIRE( soldier->getDamage() == 10 );

        fireball->action(soldier);
        REQUIRE( soldier->getHitPoint() == 85 );

        }
}
