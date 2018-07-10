#include "catch.hpp"
#include "../State/MagState.h"

TEST_CASE( "Test of MagState class" ) {
    int mana = 20;
    MagState *magState = new MagState(mana);

    REQUIRE( magState->getMana() == mana );
    REQUIRE( magState->getManaLim() == mana );
    
    SECTION( "MagState::spendMana test" ) {
     	magState->spendMana(15);

     	REQUIRE( magState->getMana() == mana-15 );
    	    REQUIRE( magState->getManaLim() == 20 );

    	    try {
    	     	magState->spendMana(15);
    	        } catch ( OutOfManaException obj ) {
    	            REQUIRE( magState->getMana() == mana-15 );
    	        }
        }
    SECTION( "MagState::adddMana test" ) {
    	    magState->spendMana(15);
    	    magState->addMana(5);

        REQUIRE( magState->getMana() == 10 );
    	    REQUIRE( magState->getManaLim() == 20 );
    }
}
