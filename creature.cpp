#include "creature.h"

/*-------- Creature Baseclass --------*/

// Taking damage for creatures
void Creature::TakeDamage(int damageAmt) {
	// Take damage
	this->setHealth(this->getHealth() - damageAmt);

	// Execute Creature's death function if health less than or equal 0
	if (getHealth() <= 0) {
		OnCreatureDeath();
	}
}

// Creature baseclass destructor
Creature::~Creature() {
	delete inventory;
}


/*-------- Player Character Subclass --------*/

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
	cout << endl;

	// Execute Player Action
	if(command < actionList.size())
		if (actionList[command])
			actionList[command]->ExecuteAction();
}


void Player::getPlayerStats() {
	cout << "Character " << getName() << " stats:" << endl;
	cout << "Health Points: " << getHealth() << endl;
	cout << "Attack Points: " << getAttack() << endl;
	cout << "Experience Points: " << getXP() << endl << endl;
}


void Player::OnCreatureDeath()
{
	cout << endl;
	cout << "~~~YOU DIED~~~" << endl;

	// Do more code with ending the game...
}



/*-------- Enemy Base Character Subclass --------*/

void Monster::OnCreatureDeath()
{
	// Do something on creature death...
}

void Monster::CreatureTurn() {
	// Use rand() for doing a random action on Monster's turn, in range of their action list
	int commandSelect = rand() % getInventory()->getActionList().size();

	// Execute this action
	getInventory()->getActionList()[commandSelect]->ExecuteAction();
}