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

    // wizard->chooseSpell();

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
        REQUIRE( wizard->getHitPoint() == wizard->getHitPointLimit());
        
        wizard->takeDamage(40);
        REQUIRE( wizard->getHitPoint() == wizard->getHitPointLimit() - 40 );

        wizard->cast(wizard, HEAL);
        REQUIRE( wizard->getHitPoint() == 90 );
    }
    SECTION( "Wizard::cast test") {

        Soldier* soldier = new Soldier();
        Werewolf* werewolf = new Werewolf();
        Vampire* vampire = new Vampire();

        REQUIRE( soldier->getHitPoint() == 100 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( soldier->getName() == "Soldier" );
        REQUIRE( soldier->getDamage() == 10 );

        REQUIRE( werewolf->getHitPoint() == 120 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( werewolf->getName() == "Werewolf" );
        REQUIRE( werewolf->getDamage() == 30 );

        REQUIRE( vampire->getHitPoint() == 150 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( vampire->getName() == "Vampire" );
        REQUIRE( vampire->getDamage() == 20 );



        // wizard->chooseSpell();
        wizard->cast(soldier, FIREBALL);
        REQUIRE( soldier->getHitPoint() == 93 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( wizard->getMana() == 90 );

        wizard->cast(soldier, LIGHTINING);
        REQUIRE( soldier->getHitPoint() == 88 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( wizard->getMana() == 85 );
        
        vampire->useAbility(wizard);
        REQUIRE( wizard->getHitPoint() == 150 );
        REQUIRE( wizard->getHitPointLimit() == 150 );
        REQUIRE( wizard->getName() == "Vampire" );
        REQUIRE( wizard->getDamage() == 20 );
        REQUIRE( wizard->getMana() == 85 );
        wizard->chooseSpell();

    }
    // SECTION( "SpellCaster::add Spell test") {

    //     Soldier* soldier = new Soldier();
    //     Spell *lightning = new Lightning(wizard);
        
    //     REQUIRE( lightning->getSpellName() == "Lightning" );
    //     REQUIRE( lightning->getActionPoint() == 10 );
    //     REQUIRE( lightning->getCost() == 5 );

    //     wizard->addSpell(lightning, LIGHTINING);

    //     wizard->chooseSpell();

    //     wizard->cast(soldier, LIGHTINING);
    //     REQUIRE( soldier->getHitPoint() == 95 );
    // }

}
