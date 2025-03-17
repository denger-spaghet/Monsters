#include "monster.h"

Monster::Monster():
    Creature { "none", '0', 0, 0, 0, 0 } {}

Monster::Monster(Type t):
    Creature { monsterData[t] } {}

Monster Monster::getRandomMonster() {
    int type { Random::get(0, Monster::Type::max_types - 1) };
    return Monster { static_cast<Monster::Type>(type) };
}

void Monster::scaleMonster(int level) {
    m_health += level;
    m_damage += level;
    m_gold += level;
    m_xp += level;
}

std::ostream& operator<<(std::ostream& os, const Monster& obj) {
    Creature c { obj };
    os << "Monster\n"
        << c << "\n";
    
    return os;
}