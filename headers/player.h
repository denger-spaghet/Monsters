#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player : public Creature {
private:
    int m_level;
    int m_levelThreshold;
public:
    Player(std::string_view name);
    Player(std::string_view name, int);

    int getLevel() const {return m_level;}
    int getLevelThreshold() const {return m_levelThreshold;}
    bool hasWon() const {return m_level >= 20;}
    void addXp(int);

    friend std::ostream& operator<<(std::ostream& os, const Player& obj);
private:
    void checkLevel();
    void levelUp();
};

#endif