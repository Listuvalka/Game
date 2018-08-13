#include "catch.hpp"
#include "../Units/Warlock.h"
#include "../Units/Demon.h"


TEST_CASE( "Test of Warlock class" ) {
    Warlock* warlock = new Warlock();

    REQUIRE( warlock->getHitPoint() == 100 );
    REQUIRE( warlock->getHitPointLimit() == 100 );
    REQUIRE( warlock->getName() == 10 );
    REQUIRE( warlock->getDamage() == 15 );
    REQUIRE( warlock->getMana() == 100);   
    REQUIRE( warlock->getManaLim() == 100 );

    SECTION( "Werewolf::transform test" ) {
        

        Demon* demon = warlock->summonDemon();
        REQUIRE( demon->getHitPoint() == 80 );
        REQUIRE( demon->getHitPointLimit() == 80 );
        REQUIRE( demon->getName() == 12 );
        REQUIRE( demon->getDamage() == 30 );
        REQUIRE( warlock->getMana() == 55);   
        REQUIRE( warlock->getManaLim() == 100 );

        try {
            warlock->cast(demon, HEAL);;
        } catch ( NoSpellInBook obj ) {}
    }
}
