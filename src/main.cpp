#include <iostream>
#include <string>
#include <cctype>

#include "player.h"
#include "monster.h"
#include "dungeon.h"

/*TODO
-polish day 
-items class
	-potions
	-weapons
	-armors
-Creature::Boss class
-server 0.0
*/

//if true option a selected
char twoChoices(char a, char b, std::string_view message) {
	bool boolA { false };
	bool boolB { false };
	char choice {};

	do {
		std::cout << message << " ";
		std::cin >> choice;
		boolA = (choice == a || choice == std::toupper(a));
		boolB = (choice == b || choice == std::toupper(b));
	} while(!boolA && !boolB);

	return (boolA ? a : b);
}

void bigDivider() {
	std::cout << "========================\n";
}

void smallDivider() {
	std::cout << "------------------------\n";
}

void attackPlayer(Player& p, Monster& m) {
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

void attackMonster(Player& p, Monster& m) {
	m.reduceHealth(p.getDamage());
	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
	if(m.isDead()) {
		p.addGold(m.getGold());
		p.levelUp();

		std::cout << "You killed the " << m.getName() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		std::cout << "You are now level " << p.getLevel() << ".\n";		
	}
}

void fightMonster(Player& p, Monster& m) {
	char userInput {};
	bool run { false };
	bool fight { false };

	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
	
	
	do{
		std::cout << "You have " << p.getHealth() << " health.\n";

		char runFight { twoChoices('r', 'f', "(R)un or (F)ight:") };

		if(runFight == 'r') {
			int roll { Random::get(1, 100) };
			if(roll > 50) {
				std::cout << "You successfully fled.\n";
				break;
			} else {
				std::cout << "You failed to flee.\n";
				attackPlayer(p, m);
			}
		} else {
			attackMonster(p, m);
			if(!m.isDead()) {
				attackPlayer(p, m);
			}
		}
		smallDivider();
	} while(!p.isDead() && !m.isDead());
	bigDivider();
}

void runDungeon(Player& p, int& level) {
	char doorChoice { ' ' };
	if(level == 0) {
		doorChoice = 'l';
	} else {
		std::cout << "There are two doors in front of you.\n";
		std::cout << "The left one leads deeper into the dungeon.\n";
		std::cout << "The right one continues on the same level.\n";

		doorChoice = twoChoices('l', 'r', "Go (L)eft or (R)ight?");
	}
	smallDivider();
	if(doorChoice == 'l') ++level;
	Dungeon d { Dungeon::generateDungoen(level, 2) };
	std::cout << d;
	Monster *monsters { d.getMonsters() };

	for(int i {0}; i < d.getSize(); i++) {
		if(p.isDead() || p.hasWon()) {
			doorChoice = ' ';
			return;
		}
		fightMonster(p, monsters[i]);
	}
	std::cout << "You survived, for now.\n";
	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";
	bigDivider();
	doorChoice = ' ';
}

int main()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p { playerName };
	int level { 0 };

	std::cout << "Welcome, " << p.getName() << ".\n";
	std::cout << "There is a door into a dungeon in front of you.\n";

	char startGame { twoChoices('y', 'n', "Do you want to enter? (y/n):") };
	while(startGame == 'n') {
		std::cout << "You cannot turn back.\n";
		startGame = twoChoices('y', 'n', "Do you want to enter? (y/n):");
	}

	bigDivider();
	do {
		runDungeon(p, level);

	} while(!p.isDead() && !p.hasWon());
	


	if(p.isDead()) {
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can’t take it with you!\n";
	} else {
		std::cout << "Congratulations, you won and took " << p.getGold() << " gold.\n";
	}

	return 0;
}