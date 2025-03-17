#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player : public Creature {
private:
    int m_level;
    int m_levelThreshold;
public:
    Player(std::string_view name);

    int getLevel() const {return m_level;}
    bool hasWon() const {return m_level >= 20;}
    void addXp(int);
private:
    void checkLevel();
    void levelUp();
};

#endif