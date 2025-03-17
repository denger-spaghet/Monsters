#include "creature.h"

Creature::Creature(
    std::string_view name,
    char symbol, 
    int maxHealth, 
    int damage, 
    int gold,
    int xp
    ):
        m_name { name },
        m_symbol { symbol },
        m_health { maxHealth },
        m_maxHealth { maxHealth },
        m_damage { damage },
        m_gold { gold },
        m_xp { xp } {}

std::ostream& operator<<(std::ostream& os, const Creature& obj) {
    os << "* Name: " << obj.getName() << "\n"
        << "* Symbol: " << obj.getSymbol() << "\n"
        << "* Health: " << obj.getHealth() << "\n"
        << "* MaxHealth: " << obj.getMaxHealth() << "\n"
        << "* Damage: " << obj.getDamage() << "\n"
        << "* Gold: " << obj.getGold() << "\n"
        << "* Xp: " << obj.getXp() << "\n";
    return os;
}