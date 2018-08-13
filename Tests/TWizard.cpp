#include "catch.hpp"
#include "../Units/Wizard.h"
#include "../Units/Vampire.h"
#include "../Units/Werewolf.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Wizard class" ) {
    int hp = 100;

    Wizard* wizard = new Wizard();

    REQUIRE( wizard->getHitPoint() == 100 );
    REQUIRE( wizard->getHitPointLimit() == 100 );
    REQUIRE( wizard->getName() == "Wizard" );
    REQUIRE( wizard->getDamage() == 5 );
    REQUIRE( wizard->getMana() == 100 );   
    REQUIRE( wizard->getManaLim() == 100 );

    SECTION( "Wizard::takeDemage test" ) {
        int damage = 10;
        int iteration = wizard->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            wizard->takeDamage(damage);
            int expectedHP = wizard->getHitPointLimit() - damage * i;
            REQUIRE( wizard->getHitPoint() == expectedHP);
            }

        try {
            wizard->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }

        try {
            wizard->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }
    }
    SECTION( "Wizard::takeMagDemage test" ) {
        int damage = 20;
        int iteration = wizard->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            wizard->takeMagDamage(damage);
            int expectedHP = wizard->getHitPointLimit() - damage * i;
            REQUIRE( wizard->getHitPoint() == expectedHP);
            }

        try {
                wizard->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }

        try {
                wizard->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }
    }
    SECTION( "Wizard::addHitPoint test") {
        wizard->takeDamage(20);
        REQUIRE( wizard->getHitPoint() == wizard->getHitPointLimit() - 20 );

        wizard->cast(wizard, HEAL);
        REQUIRE( wizard->getHitPoint() == 95 );
        
        wizard->takeDamage(40);
        REQUIRE( wizard->getHitPoint() == 55 );

        wizard->cast(wizard, HEAL);
        REQUIRE( wizard->getHitPoint() == 70 );
    }
    SECTION( "Wizard::cast test") {

        Soldier* soldier = new Soldier();
        
        REQUIRE( soldier->getHitPoint() == 100 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( soldier->getName() == "Soldier" );
        REQUIRE( soldier->getDamage() == 10 );



        wizard->chooseSpell();
        wizard->cast(soldier, FIREBALL);
        REQUIRE( soldier->getHitPoint() == 85 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( wizard->getMana() == 90 );

        wizard->cast(soldier, LIGHTINING);
        REQUIRE( soldier->getHitPoint() == 75 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( wizard->getMana() == 85 );
    }   
    SECTION( "Fight between Wizard and Vampire") {

        Vampire* vampire = new Vampire();

        REQUIRE( vampire->getHitPoint() == 150 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( vampire->getName() == "Vampire" );
        REQUIRE( vampire->getDamage() == 20 );


        wizard->cast(vampire, LIGHTINING);
        REQUIRE( vampire->getHitPoint() == 140 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( wizard->getHitPoint() == 100 );
        REQUIRE( wizard->getMana() == 95 );

        wizard->attack(vampire);
        REQUIRE( vampire->getHitPoint() == 145 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( wizard->getHitPoint() == 90 );
        REQUIRE( wizard->getMana() == 95 );
        
        vampire->useAbility(wizard);
        REQUIRE( wizard->getHitPoint() == 150 );
        REQUIRE( wizard->getHitPointLimit() == 150 );
        REQUIRE( wizard->getName() == "Vampire" );
        REQUIRE( wizard->getDamage() == 20 );
        
        try {
            wizard->getMana();
        } catch ( UnitHaveNotMagState obj ) {}
        
        try {
            wizard->chooseSpell();
        } catch ( UnitHaveNotMagState obj ) {}
    }
    SECTION( "Fight between Wizard and Werewolf") {
        Werewolf* werewolf = new Werewolf();

        REQUIRE( werewolf->getHitPoint() == 120 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( werewolf->getName() == "Werewolf" );
        REQUIRE( werewolf->getDamage() == 30 );

        wizard->chooseSpell();
        wizard->cast(werewolf, FIREBALL);
        REQUIRE( werewolf->getHitPoint() == 105 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( wizard->getHitPoint() == 100 );
        REQUIRE( wizard->getMana() == 90 );

        
        werewolf->useAbility(wizard);
        REQUIRE( wizard->getHitPoint() == 120 );
        REQUIRE( wizard->getHitPointLimit() == 120 );
        REQUIRE( wizard->getName() == "Werewolf" );
        REQUIRE( wizard->getDamage() == 30 );
        
        try {
            wizard->getMana();
        } catch ( UnitHaveNotMagState obj ) {}
        
        try {
            wizard->chooseSpell();
        } catch ( UnitHaveNotMagState obj ) {}


    }

}
