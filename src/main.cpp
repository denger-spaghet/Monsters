#include <iostream>
#include <string>
#include <cctype>

#include "player.h"
#include "monster.h"
#include "dungeon.h"
#include "input.h"

/*TODO
- implement new input
===============
- REFACTOR
	- global defaults
===============
- save game
- server 0.0
- cheats
	- add health
	- add xp
- add items class
	-potions??????
	-weapons
	-armors
- implement Creature::Boss class (dragon)
- implement shop
- spawn different mosnter types according to dungeon level
- refine combat
- save game

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

		std::cout << "You killed the " << m.getName() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";	
	
		p.addXp(m.getXp());
	}
}

void fightMonster(Player& p, Monster& m) {
	char userInput {};
	bool run { false };
	bool fight { false };

	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
	
	
	do{
		std::cout << "You have " << p.getHealth() << " health.\n";
		Input runFight { "Run or Fight", Input::Type::runFight };

		if(runFight.getValue() == Input::Value::run) {
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
	if(level == 0){
		++level;
	} else {
		std::cout << "There are two doors in front of you.\n";
		std::cout << "The left one leads deeper into the dungeon.\n";
		std::cout << "The right one continues on the same level.\n";

		Input doorChoice { "Go Left or Right?", Input::Type::leftRight };

		smallDivider();
		if(doorChoice.getValue() == Input::Value::left) ++level;
	}
	
	Dungeon d { Dungeon::generateDungoen(level) };
	std::cout << d;
	Monster *monsters { d.getMonsters() };

	for(int i {0}; i < d.getSize(); i++) {
		fightMonster(p, monsters[i]);
		if(p.isDead()) {
			return;
		}
	}
	std::cout << "You survived, for now.\n";
	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";
	bigDivider();
}

int main()
{
	Input playerName { "Enter your name" };

	Player p { playerName.getString() };
	int level { 0 };

	std::cout << "Welcome, " << p.getName() << ".\n";
	std::cout << "There is a door into a dungeon in front of you.\n";


	Input startGame { "Do you want to enter?", Input::Type::yesNo };
	while(startGame.getValue() == Input::Value::no) {
		std::cout << "You cannot turn back.\n";
		startGame = Input { "Do you want to enter?", Input::Type::yesNo };
	}

	bigDivider();
	do {
		runDungeon(p, level);
		p.addFullHealth();

	} while(!p.isDead());

	if(p.isDead()) {
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can’t take it with you!\n";
	} else {
		std::cout << "Congratulations, you won and took " << p.getGold() << " gold.\n";
	}
	return 0;
}