#include "player.h"

Player::Player(std::string_view name):
    Creature { name, '@', 100, 1, 0, 0 },
    m_level { 1 },
    m_levelThreshold { m_level * 10 } {}

void Player::addXp(int xp) {
    m_xp += xp;
    checkLevel();
}

void Player::checkLevel() {
    while(m_xp >= m_levelThreshold) {
        levelUp();
    }
}

void Player::levelUp() {
    ++m_level;
    ++m_maxHealth;
    addFullHealth();

    m_xp -= m_levelThreshold;
    m_levelThreshold = m_level * 10; 
}