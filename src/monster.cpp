#include "monster.h"

Monster::Monster(Type t):
    Creature { monsterData[t] } {}

Monster Monster::getRandomMonster() {
    int type { Random::get(0, Monster::Type::max_types - 1) };
    return Monster { static_cast<Monster::Type>(type) };
}