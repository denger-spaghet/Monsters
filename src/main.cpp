#include <iostream>
#include <string>
#include "player.h"
#include "monster.h"


int main()
{
	/*std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p{ playerName };
	std::cout << "Welcome, " << p.getName() << ".\n";

	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";

	return 0;*/

	for (int i{ 0 }; i < 10; ++i)
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}

	return 0;
}