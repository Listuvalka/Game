#include "catch.hpp"
#include "../Units/Vampire.h"
#include "../Units/Soldier.h"
#include "../Units/Werewolf.h"
#include <iostream>

TEST_CASE( "Test of Vampire class" ) {
    int hp = 150;
    Vampire* vampire = new Vampire();
    REQUIRE( vampire->getHitPoint() == hp );
    REQUIRE( vampire->getHitPointLimit() == hp );
    REQUIRE( vampire->getName() == "Vampire" );
    REQUIRE( vampire->getDamage() == 20 );
    
    SECTION( "Vampire::takeDemage test" ) {
      	int damage = 50;
     	int iteration = vampire->getHitPoint()/damage;
//
     	for ( int i = 1; i <= iteration; i++ ) {
     	vampire->takeDamage(damage);
    		int expectedHP = vampire->getHitPointLimit() - damage * i;
    		REQUIRE( vampire->getHitPoint() == expectedHP);
    	    }

     	try {
     		vampire->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( vampire->getHitPoint() == 0 );
        }

 	    try {
 	    	    vampire->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( vampire->getHitPoint() == 0 );
        }
    }
    SECTION( "Vampire::takeMagDemage test" ) {
      	int damage = 10;
     	int iteration = vampire->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     		vampire->takeMagDamage(damage);
    		    int expectedHP = vampire->getHitPointLimit() - damage * i;

    		    REQUIRE( vampire->getHitPoint() == expectedHP);
    	    }

     	try {
     		vampire->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( vampire->getHitPoint() == 0 );
        }

 	    try {
 	    	    vampire->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( vampire->getHitPoint() == 0 );
        }
    }
    SECTION( "Vampire::addHitPoint test" ) {
    	    vampire->takeDamage(20);
    	    REQUIRE( vampire->getHitPoint() == vampire->getHitPointLimit() - 20);

    	    vampire->addHitPoint(15);
    	    REQUIRE( vampire->getHitPoint() == vampire->getHitPointLimit() - 5);

    	    vampire->addHitPoint(20);
    	    REQUIRE( vampire->getHitPoint() == vampire->getHitPointLimit());
    }
    SECTION( "Vampire::attack test" ) {
      	int damage = 10;
    	    Soldier* enemy = new Soldier();

    	    REQUIRE( enemy->getHitPoint() == 100 );
    	    REQUIRE( enemy->getHitPointLimit() == 100 );
    	    REQUIRE( enemy->getName() == "Soldier" );
    	    REQUIRE( enemy->getDamage() == damage );

    	    vampire->attack(enemy);
    	    REQUIRE( vampire->getHitPoint() == 145 );
    	    REQUIRE( enemy->getHitPoint() == enemy->getHitPointLimit() - vampire->getDamage());

    	    vampire->attack(enemy);
    	    vampire->attack(enemy);
    	    vampire->attack(enemy);

    	    REQUIRE( vampire->getHitPoint() == 145 );
    	    REQUIRE( enemy->getHitPoint() == enemy->getHitPointLimit() - (vampire->getDamage()) * 4 );

    }

    SECTION( "Vampire::infect test" ) {
        int damage = 10;
        Soldier* enemy = new Soldier();
        Werewolf* werewolf = new Werewolf();
        
        REQUIRE( enemy->getHitPoint() == 100 );
        REQUIRE( enemy->getHitPointLimit() == 100 );
        REQUIRE( enemy->getName() == "Soldier" );
        REQUIRE( enemy->getDamage() == damage );

        REQUIRE( werewolf->getHitPoint() == 120 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( werewolf->getName() == "Werewolf" );
        REQUIRE( werewolf->getDamage() == 30 );

        vampire->useAbility(enemy);

        REQUIRE( enemy->getHitPoint() == 150 );
        REQUIRE( enemy->getHitPointLimit() == 150 );
        REQUIRE( enemy->getName() == "Vampire" );
        REQUIRE( enemy->getDamage() == 20 );

        enemy->attack(werewolf);
        REQUIRE( enemy->getHitPoint() == 135 );
        REQUIRE( werewolf->getHitPoint() == 100 );

        enemy->useAbility(werewolf);

        REQUIRE( werewolf->getHitPoint() == 100 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( werewolf->getName() == "Werewolf" );
        REQUIRE( werewolf->getDamage() == 30 );

    }

}
