#include "dungeon.h"

Dungeon::Dungeon(Monster *monsters, int size, int level):
    m_monsters { monsters }, m_size { size }, m_level { level } {
        ++m_order;
    }
Dungeon::~Dungeon() {
    delete [] m_monsters;
}

Dungeon Dungeon::generateDungoen(int level) {
    int size = {getSizeByLevel(level)};
    Monster *monsters = new Monster[size];
    for(int i {0}; i < size; i++) {
        monsters[i] = Monster::getRandomMonster();
        monsters[i].scaleMonster(level);
    }
    return Dungeon { monsters, size, level };
}

std::ostream& operator<<(std::ostream& os, const Dungeon& obj) {
    os << "Dungeon level: " << obj.m_level 
        << " size: " << obj.m_size
        << " order: " << obj.m_order 
        << "\n";
    os << "[";
    for(int i {0}; i < obj.m_size; i++) {
        os << obj.m_monsters[i].getName() << ", ";
    }
    os << "]\n";
    return os;
}

int Dungeon::getSizeByLevel(int level) {
    return ((level / 5) + 1) * 5;
}