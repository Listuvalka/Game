#include "catch.hpp"
#include "../State/State.h"

TEST_CASE( "Test of state class" ) {
    int hp = 100;
    State *state = new State("Union", hp, 10);
    REQUIRE( state->getHitPoint() == hp );
    REQUIRE( state->getHitPointLimit() == hp );
    REQUIRE( state->getName() == "Union" );
    REQUIRE( state->getDamage() == 10 );
    
}
