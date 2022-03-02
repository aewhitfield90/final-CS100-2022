#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "Inventory.h"

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

	// Constructor
	Creature();

	// Get Functions
	string getName() { return name; }

	int getHealth() { return healthPoints; }

	int getAttack() { return attackPoints; }

	Inventory* getInventory() { return inventory; }

	// Returns Creature's current Target whenever they use an attack
	Creature* getTarget() { return target; }

	// Set Functions
	void setName(string n) { name = n; }

	void setHealth(int i) { healthPoints = i; }

	void setAttack(int i) { attackPoints = i; }

	void setTarget(Creature* in_target) { this->target = in_target; }

	void setInventory(Inventory* inInv) { this->inventory = inInv; }

	// Combat Functions
	// Deal damage to Creature's target
	void DealDamageToTarget(int damageAmt);

	// Creature's turn to do things...
	virtual void CreatureTurn() = 0;

	// Destructor
	virtual ~Creature();

};


/*-------- Player Character Subclass --------*/
class Player : public Creature {
private:
	int experiencePoints = 0;
	//Item *inventoryArray = new Item[5]; //item array of item objects size 5

public:
	//Constructor
	Player(string n, int health, int attack); //first time character creation stats

	int getXP() {return experiencePoints;}

	void getPlayerStats();

	// Override Turn function for Player
	virtual void CreatureTurn();
};


/*-------- Enemy Base Character Subclass --------*/
class Monster : public Creature {
private:
	int loot = rand() % 100 + 1; //have to wait for loot class to be made

public:
	int getLoot() {return loot; } //place holder till loot class is finished

	// Override Turn function for Monsters
	virtual void CreatureTurn();
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

#endif /* CREATURE_H */