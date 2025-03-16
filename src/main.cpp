#include <iostream>
#include <string>
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
		do {
			std::cout << "(R)un or (F)ight: ";
			std::cin >> userInput;
			run = (userInput == 'r' || userInput == 'R');
			fight = (userInput == 'f' || userInput == 'F');
		} while(!run && !fight);

		if(run) {
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

	} while(!p.isDead() && !m.isDead());
	smallDivider();
}


int main()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p { playerName };
	int level { 0 };
	char enterDungeon {};
	char leftRight {};
	bool yes { false };
	bool no { false };
	bool left { false };
	bool right { false };

	std::cout << "Welcome, " << p.getName() << ".\n";
	std::cout << "There is a door into a dungeon in front of you.\n";

	do {
		std::cout << "Do you want to enter? (y/n): ";
		std::cin >> enterDungeon;
		yes = (enterDungeon == 'y' || enterDungeon == 'Y');
		no = (enterDungeon == 'n' || enterDungeon == 'N');
		if(no) std::cout << "You cannot turn back.\n";
	} while (!yes);
	bigDivider();
	do {
		if(level == 0) {
			left = true;
		} else {
			std::cout << "There are two doors in front of you.\n";
			std::cout << "The left one leads deeper into the dungeon.\n";
			std::cout << "The right one stays on the same level.\n";
			do {
				std::cout << "Go (L)eft or (R)ight? ";
				std::cin >> enterDungeon;
				left = (enterDungeon == 'l' || enterDungeon == 'L');
				right = (enterDungeon == 'r' || enterDungeon == 'R');
			} while (!left && !right);
		}
		smallDivider();
		if(left) ++level;
		Dungeon d { Dungeon::generateDungoen(level, 2) };
		std::cout << d;
		Monster *monsters { d.getMonsters() };

		for(int i {0}; i < d.getSize(); i++) {
			if(p.isDead() || p.hasWon()) {
				break;
			}
			fightMonster(p, monsters[i]);
		}
		std::cout << "You survived, for now.\n";
		std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";
		bigDivider();
		right = false;
		left = false;

	} while(!p.isDead() && !p.hasWon());
	


	if(p.isDead()) {
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can’t take it with you!\n";
	} else {
		std::cout << "Congratulations, you won and took " << p.getGold() << " gold.\n";
	}

	return 0;
}