#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player : public Creature {
private:
    int m_level;
public:
    Player(std::string_view name);

    int getLevel() const {return m_level;}
    void levelUp ();
    bool hasWon() const {return m_level >= 20;}
};

#endif