#include <iostream>
#include <display.h>

virtual void DisplayHealth::showElement(Creature* creature) {
	std::cout << "Health: " << creature->getHealth(); << " HP" << std::endl;
};

virtual void DisplayPlayerHealth::showElement(Player* player) {
	std::cout << "Your health: " << player->getHealth(); << " HP" << std::endl;
};

virtual void DisplayMonsterHealth::showElement(Monster* monster) {
	std::cout << monster->getName(); << " health: " << monster->getHealth(); << " HP" << std::endl;
};