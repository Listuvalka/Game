
#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* name, int hitPoint, int damage, int mana, const char* type):
    Unit(new State(name, hitPoint, damage), type), 
    magState(new MagState(mana)) {
        this->ability = new DefAbility(this);
        this->m_spellBook = new std::map<enSp, Spell*>();
}

SpellCaster:: ~SpellCaster() {
	delete(this->magState);
	delete(this->m_spellBook);
    delete(this->spell);
}

enSp* SpellCaster::getSpellName() const {
    return this->spell->getSpellName();
}

int SpellCaster::getMana() const {
	return this->magState->getMana();
}
int SpellCaster::getManaLim() const {
	return this->magState->getManaLim();
}

void SpellCaster::addMana(int extra) {
	this->magState->addMana(extra);
}
void SpellCaster::spendMana(int cost) {
	this->magState->spendMana(cost);
}

void SpellCaster::delBook() {
    delete(this->m_spellBook);
    delete(this->spell);
}

void SpellCaster::addSpell(Spell* newSpell, enSp key) {
    if ( (*this->m_spellBook).find(key) != (*this->m_spellBook).end() ) {
        std::cout << "Such Key Already Exist" << std::endl;
        throw SuchKeyAlreadyExist();
    }
    this->spell = newSpell;
    this->key = key;
    this->m_spellBook->insert(std::pair<enSp, Spell*>(key, spell)); 
}
void SpellCaster::chooseSpell() {
    for (std::map<enSp, Spell*>::iterator it = m_spellBook->begin(); it != m_spellBook->end(); ++it ) {
        std::cout << it->first << " " << it->second->getSpellName()<< "\n";
    }
}
void SpellCaster::cast(Unit* target, enSp key) {
    // if ( (*this->m_spellBook).find(key) == (*this->m_spellBook).end() ) {
    //     std::cout << "No Such Key" << std::endl;
    //     throw NoSuchKey();
    // }
    this->state->ensureIsAlive();
	(*this->m_spellBook)[key]->action(target);
    this->magState->spendMana((*this->m_spellBook)[key]->getCost());

}
