#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"
#include "myRandom.h"

class Monster : public Creature {
public:
    enum Type : int {
        dragon,
        orc,
        slime,
        max_types,
    };
private:
    static inline Creature monsterData[] {
        Creature { "dragon", 'D', 20, 4, 100 },
        Creature { "orc", 'o', 4, 2, 25 },
        Creature { "slime", 's', 1, 1, 10 },
    };
public:
    Monster(Type);
    static Monster getRandomMonster();
};

#endif