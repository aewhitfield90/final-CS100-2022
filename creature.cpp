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
	vector<Item*> itemList = getInventory()->getItemList();

	for (int i = 0; i < actionList.size(); i++)
	{
		cout << "\t" << "[" << i << "] " << actionList[i]->getName();
	}
	cout << endl;

	// Get Player Input
	cin >> command;
	cout << endl;

	// Execute Player Action
	if (command < actionList.size()) {
		bool itemUsed = false;
		if (actionList[command]) {
			if (actionList[command]->getName() == "Item") {
				cout << "What item will you use? Type # next to command..." << endl;
				for (int i = 0; i < itemList.size(); i++)
				{
					cout << "\t" << "[" << i << "] " << itemList[i]->getName();
				}
				cout << endl;
				// Get Player Input
				cin >> command;
				cout << endl;
				if (command < itemList.size())
				{
					if (itemList[command]) {
						itemList[command]->ExecuteAction();
						itemUsed = true;
					}
				}
			}
			if(!itemUsed)
			actionList[command]->ExecuteAction();
		}
	}
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
	getLoot();
	this_thread::sleep_for(chrono::seconds(1));
}

void Monster::CreatureTurn() {
	// Use rand() for doing a random action on Monster's turn, in range of their action list
	int commandSelect = rand() % getInventory()->getActionList().size();

	// Execute this action
	getInventory()->getActionList()[commandSelect]->ExecuteAction();
}

void Monster::getLoot(){
	if (loot < 30) {
		getTarget()->getInventory()->getItemList().push_back(new Potion(getTarget()->getInventory()));
		cout << "You recieved a Potion from defeating " << getName();
		cout << endl;
	}
	else if (loot < 70 && loot >29) {
		getTarget()->getInventory()->getItemList().push_back(new Bomb(getTarget()->getInventory()));
		cout << "You recieved a Bomb from defeating " << getName();
		cout << endl;
	}
	else {
		cout << "No items dropped from " << getName();
		cout << endl;
	}
}