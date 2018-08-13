
#include "SpellCaster.h"

SpellCaster::SpellCaster(enName name, int hitPoint, int damage, int mana, const char* type):
    Unit(name, new State(hitPoint, damage), type), 
    magState(new MagState(mana)) {
        this->ability = new DefAbility(this);
        this->m_spellBook = new std::map<enSp, Spell*>();
}

SpellCaster:: ~SpellCaster() {
    for (std::map<enSp, Spell*>::iterator it = m_spellBook->begin(); it != m_spellBook->end(); ++it ) {
        delete (it->second);
    }
    this->m_spellBook->clear();
    delete(this->magState);
    delete(this->spell);
}

enSp SpellCaster::getSpellName() const {
    return this->spell->getSpellName();
}

int SpellCaster::getMana() const {
    if ( this->magState == nullptr ) {
        throw UnitHaveNotMagState();
    }
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
    for (std::map<enSp, Spell*>::iterator it = m_spellBook->begin(); it != m_spellBook->end(); ++it ) {
        delete (it->second);
    }
    this->m_spellBook->clear();
    
    this->m_spellBook = nullptr;
    // if ( this->m_spellBook == nullptr ) {
    //     std::cout << "m_spellBook.size() is 0" << '\n';
    // }
    delete(this->magState);
    this->magState = nullptr; 
    // delete(this->spell); 
    // this->spell = nullptr;

}

void SpellCaster::addSpell(Spell* newSpell, enSp key) {
    if ( (*this->m_spellBook).find(key) != (*this->m_spellBook).end() ) {
        // std::cout << "Such Key Already Exist" << std::endl;
        throw SuchKeyAlreadyExist();
    }
    this->spell = newSpell;
    this->key = key;
    this->m_spellBook->insert(std::pair<enSp, Spell*>(key, spell)); 
}
void SpellCaster::chooseSpell() {
    if ( this->m_spellBook == nullptr ) {
         throw UnitHaveNotMagState();       
    } else {
        for (std::map<enSp, Spell*>::iterator it = m_spellBook->begin(); it != m_spellBook->end(); ++it ) {
            std::cout << it->first << " " << it->second->getSpellName() << std::endl;
        }
    }
}
void SpellCaster::cast(Unit* target, enSp key) {
    this->state->ensureIsAlive();
    
    if ( this->m_spellBook == nullptr ) {
        throw UnitHaveNotMagState();       
    }
    if ( this->m_spellBook->empty() ) {
        throw NoSpellInBook();
    }
    if ( this->m_spellBook->find(key) == this->m_spellBook->end() ) {
        // std::cout << "No Such Key" << std::endl;
        throw NoSuchKey();
    }

	(*this->m_spellBook)[key]->action(target);
    this->magState->spendMana((*this->m_spellBook)[key]->getCost());

}
