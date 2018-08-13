#include "catch.hpp"
#include "../Units/Werewolf.h"
#include "../Units/Soldier.h"
#include "../Units/Vampire.h"
#include <iostream>

TEST_CASE( "Test of Werewolf class" ) {
    int hp = 120;
    Werewolf* werewolf = new Werewolf();
    REQUIRE( werewolf->getHitPoint() == hp );
    REQUIRE( werewolf->getHitPointLimit() == hp );
    REQUIRE( werewolf->getName() == 5 );
    REQUIRE( werewolf->getDamage() == 30 );
    
    SECTION( "Werewolf::takeDemage test" ) {
      	int damage = 50;
     	int iteration = werewolf->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     	werewolf->takeDamage(damage);
    		int expectedHP = werewolf->getHitPointLimit() - damage * i;
    		REQUIRE( werewolf->getHitPoint() == expectedHP);
    	    }

     	try {
     		werewolf->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( werewolf->getHitPoint() == 0 );
        }

 	    try {
 	    	    werewolf->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( werewolf->getHitPoint() == 0 );
        }
    }
    SECTION( "Werewolf::takeMagDemage test" ) {
      	int damage = 10;
     	int iteration = werewolf->getHitPoint()/damage;

     	for ( int i = 1; i <= iteration; i++ ) {
     		werewolf->takeMagDamage(damage);
    		    int expectedHP = werewolf->getHitPointLimit() - damage * i;

    		    REQUIRE( werewolf->getHitPoint() == expectedHP);
    	    }

     	try {
     		werewolf->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( werewolf->getHitPoint() == 0 );
        }

 	    try {
 	    	    werewolf->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( werewolf->getHitPoint() == 0 );
        }
    }
    SECTION( "Werewolf::addHitPoint test" ) {
    	werewolf->takeDamage(20);
    	REQUIRE( werewolf->getHitPoint() == werewolf->getHitPointLimit() - 20);

        werewolf->addHitPoint(15);
	    REQUIRE( werewolf->getHitPoint() == werewolf->getHitPointLimit() - 5);

    	werewolf->addHitPoint(20);
    	REQUIRE( werewolf->getHitPoint() == werewolf->getHitPointLimit());
    }
    SECTION( "Werewolf::attack test" ) {
      	int damage = 10;
    	Soldier* enemy = new Soldier();

    	REQUIRE( enemy->getHitPoint() == 100 );
    	REQUIRE( enemy->getHitPointLimit() == 100 );
    	REQUIRE( enemy->getName() == 1 );
    	REQUIRE( enemy->getDamage() == damage );

    	werewolf->attack(enemy);
        REQUIRE( werewolf->getHitPoint() == 115 );
    	REQUIRE( enemy->getHitPoint() == 70 );

    	werewolf->attack(enemy);
    	werewolf->attack(enemy);
    	
    	REQUIRE( werewolf->getHitPoint() == 105 );
    	REQUIRE( enemy->getHitPoint() == 10 );

    }

    SECTION( "Werewolf::infect test" ) {
        int damage = 10;
        Soldier* enemy = new Soldier();
        Vampire* vampire = new Vampire();

        REQUIRE( enemy->getHitPoint() == 100 );
        REQUIRE( enemy->getHitPointLimit() == 100 );
        REQUIRE( enemy->getName() == 1 );
        REQUIRE( enemy->getDamage() == damage );

        REQUIRE( vampire->getHitPoint() == 150 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( vampire->getName() == 4 );
        REQUIRE( vampire->getDamage() == 20 );

        werewolf->useAbility(enemy);

        REQUIRE( enemy->getHitPoint() == 120 );
        REQUIRE( enemy->getHitPointLimit() == 120 );
        REQUIRE( enemy->getName() == 5 );
        REQUIRE( enemy->getDamage() == 30 );

        enemy->useAbility(vampire);

        REQUIRE( vampire->getHitPoint() == 150 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( vampire->getName() == 4 );
        REQUIRE( vampire->getDamage() == 20 );
    }

    SECTION( "Werewolf::transform test" ) {
        Soldier* enemy = new Soldier();

        werewolf->useAbilityTR();
        REQUIRE( werewolf->getHitPoint() == 150 );
        REQUIRE( werewolf->getHitPointLimit() == 150 );
        REQUIRE( werewolf->getName() == 6 );
        REQUIRE( werewolf->getDamage() == 35 );

        enemy->useAbilityTR();

        REQUIRE( enemy->getHitPoint() == 100 );
        REQUIRE( enemy->getHitPointLimit() == 100 );
        REQUIRE( enemy->getName() == 1 );
        REQUIRE( enemy->getDamage() == 10 );

    }
    SECTION( "Wolf::takeMagDemage test" ) {
        werewolf->useAbilityTR();

        REQUIRE( werewolf->getHitPoint() == 150 );
        REQUIRE( werewolf->getHitPointLimit() == 150 );
        REQUIRE( werewolf->getName() == 6 );
        REQUIRE( werewolf->getDamage() == 35 );

        int damage = 20;
       
        werewolf->takeMagDamage(damage);

        REQUIRE( werewolf->getHitPoint() == 120);

        werewolf->useAbilityTR();
        REQUIRE( werewolf->getHitPoint() == 120 );
        REQUIRE( werewolf->getHitPointLimit() == 150 );
        REQUIRE( werewolf->getName() == 6 );
        REQUIRE( werewolf->getDamage() == 35 );
        
    }
    SECTION( "Wolf::takeDemage test" ) {
        werewolf->useAbilityTR();

        REQUIRE( werewolf->getHitPoint() == 150 );
        REQUIRE( werewolf->getHitPointLimit() == 150 );
        REQUIRE( werewolf->getName() == 6 );
        REQUIRE( werewolf->getDamage() == 35 );

        int damage = 20;
       
        werewolf->takeDamage(damage);

        REQUIRE( werewolf->getHitPoint() == 130);
        
    }

}
