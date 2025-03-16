#ifndef DUNGEON_H
#define DUNGEON_H

#include "monster.h"
#include <iostream>

class Dungeon {
private:
    Monster *m_monsters;
    int m_level;
    int m_size;
    inline static int m_order {0};
    Dungeon(Monster*, int, int);
public:
    Dungeon(const Dungeon&) = delete;

    Monster* getMonsters() {return m_monsters;}
    int getLevel() {return m_level;}
    int getSize() {return m_size;}
    int getNumber() {return m_order;}

    static Dungeon generateDungoen(int, int);
    friend std::ostream& operator<<(std::ostream& os, const Dungeon& obj);

    ~Dungeon();
};

#endif
