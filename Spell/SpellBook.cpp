#include "SpellBook.h"

SpellBook::SpellBook(Spell* spell, enSp key) {
    this->spell = spell;
    this->key = key;
    this->m_spellBook = new std::map<enSp, Spell*>();
    this->m_spellBook->insert(std::pair<enSp, Spell*>(key, spell)); 

}
SpellBook:: ~SpellBook() {
	delete(this->spell);
    delete(this->m_spellBook);
}
const char* SpellBook::getSpellName() const {
    return this->spell->getSpellName();
}

void SpellBook::addSpell(Spell* newSpell, enSp key) {
    this->spell = newSpell;
	this->m_spellBook->insert(std::pair<enSp, Spell*>(key, spell)); 
}

void SpellBook::chooseSpell() {
    for (std::map<enSp, Spell*>::iterator it = m_spellBook->begin(); it != m_spellBook->end(); ++it ) {
        std::cout << it->first << " " << it->second->getSpellName()<< "\n";
    }
}

void SpellBook::cast(Unit *target, enSp key) {
	// (*this->m_spellBook)[key]->getActionPoint();
    (*this->m_spellBook)[key]->action(target);
}
