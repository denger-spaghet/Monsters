#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
    protected:
        std::string m_name;
        char m_symbol;
        int m_health;
        int m_damage;
        int m_gold;
    public:
        Creature(std::string_view, char, int, int, int);
    
        std::string getName() const {return m_name;}
        char getSymbol() const {return m_symbol;}
        int getHealth() const {return m_health;}
        int getDamage() const {return m_damage;}
        int getGold() const {return m_gold;}
    
        void reduceHealth(int n) {m_health -= n;}
        bool isDead() {return (m_health <= 0);}
        void addGold(int n) {m_gold += n;}
    };

#endif