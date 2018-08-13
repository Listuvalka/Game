#include "IObserveble.h"

// void IObserveble::addToList(Unit* flagged) {
//     list->push_back(flagged);
// }

// void IObserveble::removeFromList(Unit* flagged) {
//     list->remove(list.begin(), list.end(), flagged)
// }

// void IObserveble::notice(int hp) {
//     for ( vector<Unit*>::const_iterator iter = list.begin(); iter != list.end(); ++iter ) {
//         if ( *iter != 0 ) {
//              ( *iter )->Update(hp);
//         }
//     }
// }


void IObserveble::setObserver(Necromancer* newObserver) {
    if ( observer == NULL ) {
        this->observer = newObserver;
    } 
}

void IObserveble::notice(int hp) {
    this->observer->updeteHP(hp);
}