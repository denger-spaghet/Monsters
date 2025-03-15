#ifndef DUNGEON_H
#define DUNGEON_H

#include "monster.h"
#include <iostream>

class Dungeon {
private:
    Monster *m_monsters;
    int m_level;
    int m_size;
    inline static int m_number {0};
    Dungeon(Monster*, int, int);
public:
    Dungeon(Dungeon&) = delete;

    int getLevel() {return m_level;}
    int getNumber() {return m_number;}

    static Dungeon generateDungoen(int, int);
    friend std::ostream& operator<<(std::ostream& os, const Dungeon& obj);

    ~Dungeon();
};

#endif
