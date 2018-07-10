all: test.out

test.out: test_main.o State.o Ability.o Unit.o DefAbility.o Soldier.o Rogue.o RogueAbility.o MagState.o Berserker.o BerserkerState.o VampireAbility.o Vampire.o WerewolfAbility.o WolfState.o Werewolf.o Spell.o Hit.o Fireball.o Heal.o SpellCaster.o Wizard.o Group.o Lightning.o TWizard.o
	g++ -o test.out test_main.o State.o Ability.o Unit.o DefAbility.o Soldier.o Rogue.o RogueAbility.o MagState.o Berserker.o BerserkerState.o VampireAbility.o Vampire.o WerewolfAbility.o WolfState.o Werewolf.o Spell.o Hit.o Fireball.o Heal.o SpellCaster.o Wizard.o Group.o Lightning.o TWizard.o 

test_main.o: 
	g++ -std=c++11 -c test_main.cpp

State.o:
	g++ -std=c++11 -c ../State/State.cpp 
	
Ability.o:
	g++ -std=c++11 -c ../Ability/Ability.cpp
	
Unit.o:
	g++ -std=c++11 -c ../Units/Unit.cpp

DefAbility.o:
	g++ -std=c++11 -c ../Ability/DefAbility.cpp

Soldier.o:
	g++ -std=c++11 -c ../Units/Soldier.cpp
	
Rogue.o:
	g++ -std=c++11 -c ../Units/Rogue.cpp

RogueAbility.o:
	g++ -std=c++11 -c ../Ability/RogueAbility.cpp
	
MagState.o:
	g++ -std=c++11 -c ../State/MagState.cpp
	
Berserker.o:
	g++ -std=c++11 -c ../Units/Berserker.cpp
	
BerserkerState.o:
	g++ -std=c++11 -c ../State/BerserkerState.cpp

VampireAbility.o:
	g++ -std=c++11 -c ../Ability/VampireAbility.cpp

Vampire.o:
	g++ -std=c++11 -c ../Units/Vampire.cpp
	
WerewolfAbility.o:
	g++ -std=c++11 -c ../Ability/WerewolfAbility.cpp

WolfState.o:
	g++ -std=c++11 -c ../State/WolfState.cpp

Werewolf.o:
	g++ -std=c++11 -c ../Units/Werewolf.cpp

# SpellBook.o:
# 	g++ -std=c++11 -c ../Spell/SpellBook.cpp

SpellCaster.o:
	g++ -std=c++11 -c ../Units/SpellCaster.cpp

# WizardSpellBook.o:
# 	g++ -std=c++11 -c ../Spell/WizardSpellBook.cpp

Wizard.o:
	g++ -std=c++11 -c ../Units/Wizard.cpp	

Spell.o:
	g++ -std=c++11 -c ../Spell/Spell.cpp

Hit.o:
	g++ -std=c++11 -c ../Spell/Hit.cpp

Group.o:
	g++ -std=c++11 -c ../Group.cpp

Lightning.o:
	g++ -std=c++11 -c ../Spell/HitSpell/Lightning.cpp

Fireball.o:
	g++ -std=c++11 -c ../Spell/HitSpell/Fireball.cpp

Heal.o:
	g++ -std=c++11 -c ../Spell/Heal.cpp

TWizard.o:
	g++ -std=c++11 -c TWizard.cpp




clean:
	rm -f *.o
