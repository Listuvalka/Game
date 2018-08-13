#ifndef GROUP_CPP
#define GROUP_CPP

#include <iostream>

enum enSp {
    FIREBALL = 1,
    LIGHTINING = 2,
    HEAL = 3,
    // PRAYER
};


enum enName {
    Union = 0,
    SOLDIER = 1,
    ROGUE = 2,
    BERSERKER = 3,
    VAMPIRE = 4,
    WEREWOLF = 5,
    WOLF = 6,
    WIZARD = 7,
    HEALER = 8,
    PRIEST = 9,
    WARLOCK = 10,
    NECROMANCER = 11,
    DEMON = 12

};


// enum Type {
//     PEOPLE = 1,
//     UNDEAD = 2,
//     CURE_MAGICIAN = 3,
//     WARRIOR_MAGICIAN = 4
// };

// Type getType(enName name) {
//     switch(name) {
//         case enName::WIZARD: 
//             return Type::WARRIOR_MAGICIAN;
//         case enName::HEALER: 
//             return Type::CURE_MAGICIAN;
//         case enName::PRIEST:
//             return Type::CURE_MAGICIAN;
//         case enName::NECROMANCER:
//             return Type::UNDEAD;
//         case enName::VAMPIRE:
//             return Type::UNDEAD;
//         default:
//             return Type::PEOPLE;
//     }
// };
#endif //GROUP_CPP