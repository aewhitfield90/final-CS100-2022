#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "Inventory.h"
#include "Actions\Action.h"

using namespace std;

/*-------- Character Base Class --------*/
class Creature {
private:
	string name = "";
	int healthPoints = 10;
	int attackPoints = 10;
	Creature* target;
	Inventory* inventory;


public:

	Creature() {
		// Creature Inventory Creation
		inventory = new Inventory;
		inventory->getActionList().push_back(new Attack);
	}

	// Get Functions
	string getName() { return name; }

	int getHealth() { return healthPoints; }

	int getAttack() { return attackPoints; }

	Inventory* getInventory() { return inventory; }

	// Returns Creature's current Target whenever they use an attack
	Creature* getTarget() { return target; }

	// Set Functions
	void setName(string n) { 
		name = n; 
	}

	void setHealth(int i) { 
		healthPoints = i; 
	}

	void setAttack(int i) { 
		attackPoints = i; }

	void setTarget(Creature* in_target) { 
		this->target = in_target; 
	}

	void setInventory(Inventory* inInv) { 
		this->inventory = inInv; 
	}

	// Combat Functions

	// Deal damage to Creature's target
	void DealDamageToTarget(int damageAmt) {
		target->setHealth(this->getHealth() - damageAmt);
	}

	// Creature's turn to do things...
	virtual void CreatureTurn() = 0;

};


/*-------- Player Character Subclass --------*/
class Player : public Creature {
private:
	int experiencePoints = 0;
	//Item *inventoryArray = new Item[5]; //item array of item objects size 5
public:
	Player(string n) {//first time character creation stats
		setName(n);
		setHealth(100);
		setAttack(5);
	}
	int getXP() {
		return experiencePoints;
	}
	void getPlayerStats() {
		cout << "Character " << getName() << " stats:" << endl;
		cout << "Health Points: " << getHealth() << endl;
		cout << "Attack Points: " << getAttack() << endl;
		cout << "Experience Points: " << getXP() << endl << endl;
	}

	// Player Turn
	virtual void CreatureTurn() {
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
		if(actionList[command])
			actionList[command]->ExecuteAction();
	}
};


/*-------- Enemy Base Character Subclass --------*/
class Monster : public Creature {
private:
	int loot = rand() % 100 + 1; //have to wait for loot class to be made

public:
	int getLoot() {
		return loot; //place holder till loot class is finished
	}

	virtual void CreatureTurn() {
		// Eventually use rand() for doing a random action
		int i = 0;
		getInventory()->getActionList()[i]->ExecuteAction();
	}
};


/*-------- Enemy Subclasses --------*/
class Slime : public Monster {
private:
public:
	Slime() {
		setName("Slime");
		setHealth(25);
		setAttack(3);
	}
};

class Rat : public Monster {
private:
public:
	Rat() {
		setName("Rat");
		setHealth(15);
		setAttack(2);
	}
};

class Skeleton : public Monster {
private:
public:
	Skeleton() {
		setName("Skeleton");
		setHealth(40);
		setAttack(5);
	}
};