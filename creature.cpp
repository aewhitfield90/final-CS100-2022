#include "creature.h"

/*-------- Creature Baseclass --------*/
Creature::Creature() {
	// Creature Inventory Creation
	inventory = new Inventory;
	inventory->getActionList().push_back(new Attack);
}


void Creature::DealDamageToTarget(int damageAmt) {
	target->setHealth(this->getHealth() - damageAmt);
}

Creature::~Creature() {
	delete inventory;
}


/*-------- Player Character Subclass --------*/
Player::Player(string n, int health, int attack) {
	setName(n);
	setHealth(health);
	setAttack(attack);
}

// Player Turn
void Player::CreatureTurn() {
	// Init get command var
	int command;

	// Ask what player will do
	cout << "What will you do? Type # next to command..." << endl;

	// Print Action List
	vector<Action*> actionList = getInventory()->getActionList();

	for (int i = 0; i < actionList.size(); i++)
	{
		cout << "\t" << "[" << i << "] " << actionList[i]->getName();
	}
	cout << endl;

	// Get Player Input
	cin >> command;

	// Execute Player Action
	if (actionList[command])
		actionList[command]->ExecuteAction();
}

void Player::getPlayerStats() {
	cout << "Character " << getName() << " stats:" << endl;
	cout << "Health Points: " << getHealth() << endl;
	cout << "Attack Points: " << getAttack() << endl;
	cout << "Experience Points: " << getXP() << endl << endl;
}



/*-------- Enemy Base Character Subclass --------*/

void Monster::CreatureTurn() {
	// Eventually use rand() for doing a random action
	int i = 0;
	getInventory()->getActionList()[i]->ExecuteAction();
}