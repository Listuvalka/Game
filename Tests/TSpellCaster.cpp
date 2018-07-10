#include "catch.hpp"
#include "../Units/SpellCaster.h"
#include "../Spell/HitSpell/Fireball.h"
#include "../Spell/HitSpell/Lightning.h"
#include "../Units/Soldier.h"

TEST_CASE( "Test of SpellCaster class" ) {
    int hp = 100;

    SpellCaster* spellCaster = new SpellCaster("Wizard", hp, 10, 20, new Fireball(), FIREBALL);

    REQUIRE( spellCaster->getHitPoint() == hp );
    REQUIRE( spellCaster->getHitPointLimit() == hp );
    REQUIRE( spellCaster->getName() == "Wizard" );
    REQUIRE( spellCaster->getDamage() == 10 );
    REQUIRE( spellCaster->getMana() == 20 );   
    REQUIRE( spellCaster->getManaLim() == 20 );

    REQUIRE( spellCaster->getSpellName() == "Fireball" );

    SECTION( "SpellCaster::takeDemage test" ) {
        int damage = 10;
        int iteration = spellCaster->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            spellCaster->takeDamage(damage);
            int expectedHP = spellCaster->getHitPointLimit() - damage * i;
            REQUIRE( spellCaster->getHitPoint() == expectedHP);
            }

        try {
                spellCaster->takeDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }

        try {
                spellCaster->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }
    }
    SECTION( "SpellCaster::takeMagDemage test" ) {
        int damage = 10;
        int iteration = spellCaster->getHitPoint()/damage;

        for ( int i = 1; i <= iteration; i++ ) {
            spellCaster->takeMagDamage(damage);
            int expectedHP = spellCaster->getHitPointLimit() - damage * i;
            REQUIRE( spellCaster->getHitPoint() == expectedHP);
            }

        try {
                spellCaster->takeMagDamage(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }

        try {
                spellCaster->addHitPoint(damage);
        } catch ( OutOfHPException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }
    }
    SECTION( "SpellCaster::addHitPoint test") {
        spellCaster->takeDamage(20);
        REQUIRE( spellCaster->getHitPoint() == spellCaster->getHitPointLimit() - 20 );

        spellCaster->addHitPoint(15);
        REQUIRE( spellCaster->getHitPoint() == spellCaster->getHitPointLimit() - 5);

        spellCaster->addHitPoint(20);
        REQUIRE( spellCaster->getHitPoint() == spellCaster->getHitPointLimit());
    }
    SECTION( "SpellCaster::cast test") {

        Soldier* soldier = new Soldier();

        REQUIRE( soldier->getHitPoint() == 100 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
        REQUIRE( soldier->getName() == "Soldier" );
        REQUIRE( soldier->getDamage() == 10 );

        spellCaster->chooseSpell();
        spellCaster->cast(soldier, FIREBALL);
        REQUIRE( soldier->getHitPoint() == 85 );
        REQUIRE( soldier->getHitPointLimit() == 100 );
    }
    SECTION( "SpellCaster::add Spell test") {

        Soldier* soldier = new Soldier();
        Spell *lightning = new Lightning();
        
        REQUIRE( lightning->getSpellName() == "Lightning" );
        REQUIRE( lightning->getActionPoint() == 10 );
        REQUIRE( lightning->getCost() == 5 );

        spellCaster->addSpell(new Lightning(), LIGHTINING);

        spellCaster->chooseSpell();

        spellCaster->cast(soldier, LIGHTINING);
        REQUIRE( soldier->getHitPoint() == 95 );
    }

}
