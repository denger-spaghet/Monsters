#include "player.h"

Player::Player(std::string_view name):
    Creature { name, '@', 100, 1, 0, 0 },
    m_level { 1 } {}

void Player::levelUp() {
    ++m_level;
    ++m_damage;
}