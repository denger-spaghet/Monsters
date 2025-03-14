#include "creature.h"

Creature::Creature(std::string_view name, char symbol, int health, int damage, int gold):
    m_name { name },
    m_symbol { symbol },
    m_health { health },
    m_damage { damage },
    m_gold { gold } {}