#include "catch.hpp"
#include "../Units/Berserker.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Berserker class" ) {
    int hp = 100;
    Berserker* berserker = new Berserker("Berserker", hp, 10);
    REQUIRE( berserker->getHitPoint() == hp );
    REQUIRE( berserker->getHitPointLimit() == hp );
    REQUIRE( berserker->getName() == "Berserker" );
    REQUIRE( berserker->getDamage() == 10 );
    
    SECTION( "Berserker::takeDemage test" ) {
      	int damage = 10;
     	int iteration = berserker->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     	berserker->takeDamage(damage);
    		int expectedHP = berserker->getHitPointLimit() - damage * i;
    		REQUIRE( berserker->getHitPoint() == expectedHP);
    	    }

     	try {
     		berserker->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( berserker->getHitPoint() == 0 );
        }

 	    try {
 	      	berserker->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( berserker->getHitPoint() == 0 );
        }
    }
    SECTION( "Berserker::takeMagDemage test" ) {
      	int damage = 10;
      	REQUIRE( berserker->getHitPoint() == hp);

     	try {
     		berserker->takeMagDamage(damage);
     	} catch ( BerserkerException obj ) {
    		REQUIRE( berserker->getHitPoint() == hp);
        }
    }
    SECTION( "Berserker::addHitPoint test") {
      	berserker->takeDamage(20);
    	    REQUIRE( berserker->getHitPoint() == berserker->getHitPointLimit() - 20 );

    	    berserker->addHitPoint(15);
    	    REQUIRE( berserker->getHitPoint() == berserker->getHitPointLimit() - 5);

    	    berserker->addHitPoint(20);
    	    REQUIRE( berserker->getHitPoint() == berserker->getHitPointLimit());

    }
    SECTION( "Berserker::attack test" ) {
          	int damage = 10;
        	    Soldier* enemy = new Soldier("Enemy", 100, damage);

        	    REQUIRE( enemy->getHitPoint() == 100 );
        	    REQUIRE( enemy->getHitPointLimit() == 100 );
        	    REQUIRE( enemy->getName() == "Enemy" );
        	    REQUIRE( enemy->getDamage() == damage );

        	    berserker->attack(enemy);
        	    REQUIRE( berserker->getHitPoint() == 95 );
        	    REQUIRE( enemy->getHitPoint() == 90 );

        	    berserker->attack(enemy);
        	    berserker->attack(enemy);
        	    berserker->attack(enemy);

        	    REQUIRE( berserker->getHitPoint() == 80 );
        	    REQUIRE( enemy->getHitPoint() == 60 );
    }

}
