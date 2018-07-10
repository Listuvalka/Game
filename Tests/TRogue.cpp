#include "catch.hpp"
#include "../Units/Rogue.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Rogue class" ) {
    int hp = 100;
    Rogue* rogue = new Rogue("Rogue", hp, 10);
    REQUIRE( rogue->getHitPoint() == hp );
    REQUIRE( rogue->getHitPointLimit() == hp );
    REQUIRE( rogue->getName() == "Rogue" );
    REQUIRE( rogue->getDamage() == 10 );
    
    SECTION( "Rogue::takeDemage test" ) {
      	int damage = 10;
     	int iteration = rogue->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     	rogue->takeDamage(damage);
    		int expectedHP = rogue->getHitPointLimit() - damage * i;
    		REQUIRE( rogue->getHitPoint() == expectedHP);
    	    }

     	try {
     		rogue->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }

 	    try {
 	    	    rogue->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }
    }
    SECTION( "Rogue::takeMagDemage test" ) {
      	int damage = 10;
     	int iteration = rogue->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     		rogue->takeMagDamage(damage);
    		    int expectedHP = rogue->getHitPointLimit() - damage * i;

    		    REQUIRE( rogue->getHitPoint() == expectedHP);
    	    }

     	try {
     		rogue->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }

 	    try {
 	    	    rogue->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }
    }
    SECTION( "Rogue::addHitPoint test" ) {
    	    rogue->takeDamage(20);
    	    REQUIRE( rogue->getHitPoint() == rogue->getHitPointLimit() - 20 );

    	    rogue->addHitPoint(15);
    	    REQUIRE( rogue->getHitPoint() == rogue->getHitPointLimit() - 5);

    	    rogue->addHitPoint(20);
    	    REQUIRE( rogue->getHitPoint() == rogue->getHitPointLimit());
    }
    SECTION( "Rogue::attack test" ) {
      	int damage = 10;
    	    Soldier* soldier = new Soldier("Soldier", 100, damage);

    	    REQUIRE( soldier->getHitPoint() == 100 );
    	    REQUIRE( soldier->getHitPointLimit() == 100 );
    	    REQUIRE( soldier->getName() == "Soldier" );
    	    REQUIRE( soldier->getDamage() == damage );

    	    rogue->attack(soldier);
    	    REQUIRE( rogue->getHitPoint() == 100 );
    	    REQUIRE( soldier->getHitPoint() == 90 );

    	    rogue->attack(soldier);
    	    rogue->attack(soldier);
    	    rogue->attack(soldier);

    	    REQUIRE( rogue->getHitPoint() == 100 );
    	    REQUIRE( soldier->getHitPoint() == 60 );

    }



}
