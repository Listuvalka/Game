#ifndef MAG_STATE_H
#define MAG_STATE_H

#include <iostream>
#include "../Exception.cpp"

class MagState {
protected:
	int mana;
	int manaLim;

public:
	MagState(int mana);
	virtual ~MagState();

	int getMana() const;
	int getManaLim() const;

	void addMana(int extra);
	void spendMana(int cost);
};
#endif//MAG_STATE_H
