#include "catch.hpp"
#include "../Units/Priest.h"
#include "../Units/Vampire.h"
#include "../Units/Werewolf.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Priest class" ) {
    Priest* priest = new Priest();

    REQUIRE( priest->getHitPoint() == 110 );
    REQUIRE( priest->getHitPointLimit() == 110 );
    REQUIRE( priest->getName() == 9 );
    REQUIRE( priest->getDamage() == 20 );
    REQUIRE( priest->getMana() == 100 );   
    REQUIRE( priest->getManaLim() == 100 );

    SECTION( "Priest::takeDemage test" ) {
        int damage = 10;
        int iteration = priest->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            priest->takeDamage(damage);
            int expectedHP = priest->getHitPointLimit() - damage * i;
            REQUIRE( priest->getHitPoint() == expectedHP);
            }

        try {
            priest->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }

        try {
            priest->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }
    }
    SECTION( "Priest::takeMagDemage test" ) {
        int damage = 20;
        int iteration = priest->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            priest->takeMagDamage(damage);
            int expectedHP = priest->getHitPointLimit() - damage * i;
            REQUIRE( priest->getHitPoint() == expectedHP);
            }

        try {
                priest->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }

        try {
                priest->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }
    }
    SECTION( "Priest::addHitPoint test") {
        priest->takeDamage(20);
        REQUIRE( priest->getHitPoint() == priest->getHitPointLimit() - 20 );

        priest->cast(priest, HEAL);
        REQUIRE( priest->getHitPoint() == 110 );
        REQUIRE( priest->getMana() == 85 );
        
        priest->takeDamage(40);
        REQUIRE( priest->getHitPoint() == 70 );


        priest->cast(priest, HEAL);
        REQUIRE( priest->getHitPoint() == 100 );
        REQUIRE( priest->getMana() == 70 );
    }
    SECTION( "Priest::cast test") {

        Soldier* soldier = new Soldier();
        
        REQUIRE( soldier->getHitPoint() == 100 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( soldier->getName() == 1 );
        REQUIRE( soldier->getDamage() == 10 );



        priest->chooseSpell();
        priest->cast(soldier, FIREBALL);
        REQUIRE( soldier->getHitPoint() == 93 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( priest->getMana() == 90 );

        priest->cast(soldier, LIGHTINING);
        REQUIRE( soldier->getHitPoint() == 88 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( priest->getMana() == 85 );
    }   
    SECTION( "Fight between Priest and Vampire") {

        Vampire* vampire = new Vampire();

        REQUIRE( vampire->getHitPoint() == 150 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( vampire->getName() == 4 );
        REQUIRE( vampire->getDamage() == 20 );


        priest->cast(vampire, LIGHTINING);
        REQUIRE( vampire->getHitPoint() == 130 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( priest->getHitPoint() == 110 );
        REQUIRE( priest->getMana() == 95 );

        priest->attack(vampire);
        REQUIRE( vampire->getHitPoint() == 100 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( priest->getHitPoint() == 100 );
        REQUIRE( priest->getMana() == 95 );

        vampire->attack(priest);
        REQUIRE( vampire->getHitPoint() == 90 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( priest->getHitPoint() == 80 );
        REQUIRE( priest->getMana() == 95 );
        
        vampire->useAbility(priest);
        REQUIRE( priest->getHitPoint() == 150 );
        REQUIRE( priest->getHitPointLimit() == 150 );
        REQUIRE( priest->getName() == 4 );
        REQUIRE( priest->getDamage() == 20 );
        
        try {
            priest->getMana();
        } catch ( UnitHaveNotMagState obj ) {}
        
        try {
            priest->chooseSpell();
        } catch ( UnitHaveNotMagState obj ) {}
    }
    SECTION( "Fight between Priest and Werewolf") {
        Werewolf* werewolf = new Werewolf();

        REQUIRE( werewolf->getHitPoint() == 120 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( werewolf->getName() == 5 );
        REQUIRE( werewolf->getDamage() == 30 );

        priest->chooseSpell();
        priest->cast(werewolf, FIREBALL);
        REQUIRE( werewolf->getHitPoint() == 113 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( priest->getHitPoint() == 110 );
        REQUIRE( priest->getMana() == 90 );

        
        werewolf->useAbility(priest);
        REQUIRE( priest->getHitPoint() == 120 );
        REQUIRE( priest->getHitPointLimit() == 120 );
        REQUIRE( priest->getName() == 5 );
        REQUIRE( priest->getDamage() == 30 );
        
        try {
            priest->getMana();
        } catch ( UnitHaveNotMagState obj ) {}
        
        try {
            priest->chooseSpell();
        } catch ( UnitHaveNotMagState obj ) {}
        
        priest->useAbilityTR();
        REQUIRE( priest->getHitPoint() == 150 );
        REQUIRE( priest->getHitPointLimit() == 150 );
        REQUIRE( priest->getName() == 6 );
        REQUIRE( priest->getDamage() == 35 );

    }

}
