#include "MagState.h"

MagState::MagState(int mana): mana(mana), manaLim(mana) {}
MagState:: ~MagState() {}

int MagState::getMana() const {
	return this->mana;
}
int MagState::getManaLim() const {
	return this->manaLim;
}

void MagState::addMana(int extra) {
	int tmpMana =  this->mana + extra;

	if ( tmpMana < this->manaLim ) {
		this->mana = tmpMana;
	} else {
		this->mana = this->manaLim;
	}
}
void MagState::spendMana(int cost) {
	if ( cost <= this->mana ) {
		this->mana -= cost;
	} else {
		throw OutOfManaException();
	}

}
