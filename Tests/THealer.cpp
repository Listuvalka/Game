#include "catch.hpp"
#include "../Units/Healer.h"
#include "../Units/Vampire.h"
#include "../Units/Werewolf.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of Healer class" ) {
    int hp = 100;

    Healer* healer = new Healer();

    REQUIRE( healer->getHitPoint() == 80 );
    REQUIRE( healer->getHitPointLimit() == 80 );
    REQUIRE( healer->getName() == 8 );
    REQUIRE( healer->getDamage() == 10 );
    REQUIRE( healer->getMana() == 80 );   
    REQUIRE( healer->getManaLim() == 80 );

    SECTION( "Healer::takeDemage test" ) {
        int damage = 10;
        int iteration = healer->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            healer->takeDamage(damage);
            int expectedHP = healer->getHitPointLimit() - damage * i;
            REQUIRE( healer->getHitPoint() == expectedHP);
            }

        try {
            healer->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }

        try {
            healer->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }
    }
    SECTION( "Healer::takeMagDemage test" ) {
        int damage = 20;
        int iteration = healer->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            healer->takeMagDamage(damage);
            int expectedHP = healer->getHitPointLimit() - damage * i;
            REQUIRE( healer->getHitPoint() == expectedHP);
            }

        try {
                healer->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }

        try {
                healer->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }
    }
    SECTION( "Healer::addHitPoint test") {
        healer->takeDamage(20);
        REQUIRE( healer->getHitPoint() == healer->getHitPointLimit() - 20 );

        healer->cast(healer, HEAL);
        REQUIRE( healer->getHitPoint() == 80 );
        
        healer->takeDamage(40);
        REQUIRE( healer->getHitPoint() == 40 );

        healer->cast(healer, HEAL);
        REQUIRE( healer->getHitPoint() == 70 );
    }
    SECTION( "Healer::cast test") {

        Soldier* soldier = new Soldier();
        
        REQUIRE( soldier->getHitPoint() == 100 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( soldier->getName() == 1 );
        REQUIRE( soldier->getDamage() == 10 );



        healer->chooseSpell();
        healer->cast(soldier, FIREBALL);
        REQUIRE( soldier->getHitPoint() == 93 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( healer->getMana() == 70 );

        healer->cast(soldier, LIGHTINING);
        REQUIRE( soldier->getHitPoint() == 88 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( healer->getMana() == 65 );
    }   
    SECTION( "Fight between Healer and Vampire") {

        Vampire* vampire = new Vampire();

        REQUIRE( vampire->getHitPoint() == 150 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( vampire->getName() == 4 );
        REQUIRE( vampire->getDamage() == 20 );


        healer->cast(vampire, LIGHTINING);
        REQUIRE( vampire->getHitPoint() == 145 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( healer->getHitPoint() == 80 );
        REQUIRE( healer->getMana() == 75 );

        healer->attack(vampire);
        REQUIRE( vampire->getHitPoint() == 145 );
        REQUIRE( vampire->getHitPointLimit() == 150 );
        REQUIRE( healer->getHitPoint() == 70 );
        REQUIRE( healer->getMana() == 75 );
        
        vampire->useAbility(healer);
        REQUIRE( healer->getHitPoint() == 150 );
        REQUIRE( healer->getHitPointLimit() == 150 );
        REQUIRE( healer->getName() == 4 );
        REQUIRE( healer->getDamage() == 20 );
        
        try {
            healer->getMana();
        } catch ( UnitHaveNotMagState obj ) {}
        
        try {
            healer->chooseSpell();
        } catch ( UnitHaveNotMagState obj ) {}
    }
    SECTION( "Fight between Healer and Werewolf") {
        Werewolf* werewolf = new Werewolf();

        REQUIRE( werewolf->getHitPoint() == 120 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( werewolf->getName() == 5 );
        REQUIRE( werewolf->getDamage() == 30 );

        healer->chooseSpell();
        healer->cast(werewolf, FIREBALL);
        REQUIRE( werewolf->getHitPoint() == 113 );
        REQUIRE( werewolf->getHitPointLimit() == 120 );
        REQUIRE( healer->getHitPoint() == 80 );
        REQUIRE( healer->getMana() == 70 );

        
        werewolf->useAbility(healer);
        REQUIRE( healer->getHitPoint() == 120 );
        REQUIRE( healer->getHitPointLimit() == 120 );
        REQUIRE( healer->getName() == 5 );
        REQUIRE( healer->getDamage() == 30 );
        
        try {
            healer->getMana();
        } catch ( UnitHaveNotMagState obj ) {}
        
        try {
            healer->chooseSpell();
        } catch ( UnitHaveNotMagState obj ) {}
        
        healer->useAbilityTR();
        REQUIRE( healer->getHitPoint() == 150 );
        REQUIRE( healer->getHitPointLimit() == 150 );
        REQUIRE( healer->getName() == 6 );
        REQUIRE( healer->getDamage() == 35 );

    }

}
