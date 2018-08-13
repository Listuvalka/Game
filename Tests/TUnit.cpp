#include "catch.hpp"
#include "../Units/Unit.h"

TEST_CASE( "Test of Unit class" ) {
    int hp = 100;
    Unit* unit = new Unit(Union, new State(hp, 10), "Unit");
    REQUIRE( unit->getHitPoint() == hp );
    REQUIRE( unit->getHitPointLimit() == hp );
    REQUIRE( unit->getName() == 0 );
    REQUIRE( unit->getDamage() == 10 );
    
    SECTION( "UNIT::takeDemage test" ) {
      	int damage = 10;
     	int iteration = unit->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
    		unit->takeDamage(damage);
    		int expectedHP = unit->getHitPointLimit() - damage * i;
    		REQUIRE( unit->getHitPoint() == expectedHP);
    	    }

     	try {
    	     	unit->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( unit->getHitPoint() == 0 );
        }

 	    try {
    		    unit->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( unit->getHitPoint() == 0 );
        }
    }
    SECTION( "UNIT::takeMagDemage test" ) {
      	int damage = 10;
     	int iteration = unit->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
    		unit->takeMagDamage(damage);
    		int expectedHP = unit->getHitPointLimit() - damage * i;
    		REQUIRE( unit->getHitPoint() == expectedHP);
    	    }

     	try {
    	     	unit->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( unit->getHitPoint() == 0 );
        }

 	    try {
    		    unit->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( unit->getHitPoint() == 0 );
        }
    }
    SECTION( "UNIT::addHitPoint test") {
    	    unit->takeDamage(20);
    	    REQUIRE( unit->getHitPoint() == unit->getHitPointLimit() - 20 );

    	    unit->addHitPoint(15);
    	    REQUIRE( unit->getHitPoint() == unit->getHitPointLimit() - 5);

    	    unit->addHitPoint(20);
    	    REQUIRE( unit->getHitPoint() == unit->getHitPointLimit());

    }

}
