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
	Creature() {
		// Creature Inventory Creation
		inventory = new Inventory;
		inventory->setCreatureOwner(this);

		// All creatures can attack
		inventory->getActionList().push_back(new Attack(inventory));
	}

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
	// Take damage to Self (Use this whenever affecting health)
	void TakeDamage(int damageAmt);

	// When the creature dies
	virtual void OnCreatureDeath() = 0;

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
	Player(string n, int health, int attack) {	//first time character creation stats
		setName(n);
		setHealth(health);
		setAttack(attack);

		// Add any unique actions
		getInventory()->getActionList().push_back(new MegaFlare(getInventory()));
		getInventory()->getActionList().push_back(new NewSlashAttack(getInventory()));
	}

	int getXP() {return experiencePoints;}

	void getPlayerStats();

	// When the Player dies
	virtual void OnCreatureDeath();

	// Override Turn function for Player
	virtual void CreatureTurn();
};


/*-------- Enemy Base Character Subclass --------*/
class Monster : public Creature {
private:
	int loot = rand() % 100 + 1;		// have to wait for loot class to be made

public:
	int getLoot() {return loot; } //place holder till loot class is finished

	// When any Monster dies
	virtual void OnCreatureDeath();

	// Override Turn function for Monsters
	virtual void CreatureTurn();
};


/*-------- Enemy Subclasses --------*/
class Slime : public Monster {
private:
public:
	Slime(string name="Slime") {
		setName(name);
		setHealth(20);
		setAttack(3);

		// Add unique actions
		getInventory()->getActionList().push_back(new SlimePounce(getInventory()));
		getInventory()->getActionList().push_back(new NewSlashAttack(getInventory()));
	}
};

class Rat : public Monster {
private:
public:
	Rat(string name = "Rat") {
		setName(name);
		setHealth(15);
		setAttack(2);
	}
};

class Skeleton : public Monster {
private:
public:
	Skeleton(string name = "Skeleton") {
		setName(name);
		setHealth(40);
		setAttack(5);
	}
};

#endif /* CREATURE_H */