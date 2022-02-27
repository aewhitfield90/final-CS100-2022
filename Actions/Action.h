#pragma once
#include <string>
#include "..\Inventory.h"
#include "..\creature.h"

using namespace std;

// Action Baseclass/Interface
class Action {
private:
	// Create Vars
	int power = 0;				// The Action's general power
	string name = "Action";		// Action's name

	Inventory* owningInventory;	// Action's owning inventory

public:
	virtual void ExecuteAction() = 0;

	// Get Functions
	string getName() { return name; }
	Inventory* getOwningInventory() { return owningInventory; }

	// Set Functions
	void setOwningInventory(Inventory* inventory) { 
		this->owningInventory = inventory;
	}

	void setName(string inName) {
		this->name = inName;
	}
};

// Item Baseclass
class Item : public Action {
private:
	int itemCount = 1;
	
public:
	Item() {
		setName("Item");
	}

	virtual void ExecuteAction() {
		itemCount -= 1;
	}
};

// Attack Action Subclass
class Attack : public Action {
private:


public:
	Attack() { 
		setName("Attack");
	}

	virtual void ExecuteAction() {
		// Deal a basic attack to owning creature's target
		Creature* ownerCreature = getOwningInventory()->getCreatureOwner();

		// Get Creature Attack Damage and Target
		int damage = ownerCreature->getAttack();
		ownerCreature->DealDamageToTarget(damage);

		// Print that we dealt damage
		cout << this->getName() << " attacks and deals " << damage << " to " << ownerCreature->getTarget()->getName();

		// Sleep for 1 second
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
};

class SpecialMagic : public Action {
private:


public:
	SpecialMagic() {
		setName("Special");
	}

	virtual void ExecuteAction() {
		
	}
};