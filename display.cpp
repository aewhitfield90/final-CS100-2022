#include <iostream>
#include "display.h"

void DisplayHealth::showElement(Creature* creature) {
	std::cout << creature->getName() << " health: " << creature->getHealth() << " HP" << std::endl;
}

void DisplayPlayerHealth::showElement(Player* player) {
	std::cout << "Your health: " << player->getHealth() << " HP" << std::endl;
}

void DisplayMonsterHealth::showElement(Monster* monster) {
	std::cout << monster->getName() << " health: " << monster->getHealth() << " HP" << std::endl;
}