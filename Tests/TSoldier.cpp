#include "catch.hpp"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Soldier class" ) {
    int hp = 100;
    Soldier* soldier = new Soldier();
    REQUIRE( soldier->getHitPoint() == hp );
    REQUIRE( soldier->getHitPointLimit() == hp );
    REQUIRE( soldier->getName() == 1 );
    REQUIRE( soldier->getDamage() == 10 );
    
    SECTION( "Soldier::takeDemage test" ) {
      	int damage = 10;
     	int iteration = soldier->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     	soldier->takeDamage(damage);
    		int expectedHP = soldier->getHitPointLimit() - damage * i;
    		REQUIRE( soldier->getHitPoint() == expectedHP);
    	    }

     	try {
     		soldier->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }

 	    try {
 	    	    soldier->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }
    }
    SECTION( "Soldier::takeMagDemage test" ) {
      	int damage = 10;
     	int iteration = soldier->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     		soldier->takeMagDamage(damage);
    		    int expectedHP = soldier->getHitPointLimit() - damage * i;

    		    REQUIRE( soldier->getHitPoint() == expectedHP);
    	    }

     	try {
     		soldier->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }

 	    try {
 	    	    soldier->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }
    }
    SECTION( "Soldier::addHitPoint test" ) {
    	    soldier->takeDamage(20);
    	    REQUIRE( soldier->getHitPoint() == soldier->getHitPointLimit() - 20 );

    	    soldier->addHitPoint(15);
    	    REQUIRE( soldier->getHitPoint() == soldier->getHitPointLimit() - 5);

    	    soldier->addHitPoint(20);
    	    REQUIRE( soldier->getHitPoint() == soldier->getHitPointLimit());
    }
    SECTION( "Soldier::attack test" ) {
      	int damage = 10;
    	    Soldier* enemy = new Soldier("Enemy", 100, damage);

    	    REQUIRE( enemy->getHitPoint() == 100 );
    	    REQUIRE( enemy->getHitPointLimit() == 100 );
    	    REQUIRE( enemy->getName() == "Enemy" );
    	    REQUIRE( enemy->getDamage() == damage );

    	    soldier->attack(enemy);
    	    REQUIRE( soldier->getHitPoint() == 95 );
    	    REQUIRE( enemy->getHitPoint() == 90 );

    	    soldier->attack(enemy);
    	    soldier->attack(enemy);
    	    soldier->attack(enemy);

    	    REQUIRE( soldier->getHitPoint() == 80 );
    	    REQUIRE( enemy->getHitPoint() == 60 );

    }



}
