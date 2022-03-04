#ifndef ACTION_H
#define ACTION_H
#include <string>

using namespace std;

// Action Baseclass/Interface
class Action {
private:
	// Create Vars
	float power = 0.f;					// The Action's general power
    string name = "Action";				// Action's name
	class Inventory* owningInventory;	// Action's owning inventory
	class Creature* ownerCreature;		// Action's owning creature

public:
	Action(Inventory*);

	// Get Functions
	string getName()				{ return name; }
	Inventory* getOwningInventory() { return owningInventory; }
	Creature* getOwnerCreature()	{ return ownerCreature; }
	float getPower()				{ return power; }

	// Set Functions
	void setOwningInventory(Inventory* inventory) { this->owningInventory = inventory; }
	void setName(string inName) { this->name = inName; }
	void setPower(float inPower){ this->power = inPower; }

	// Execute Action
	virtual void ExecuteAction() = 0;


	// Modify Health function for the owning creature (Used for healing or taking damage to self)
	void ModifyOwnerHealth(int damageAmt);

	// Deal damage to owner creature's current target
	int DealDamageToTarget();
};


// Item Baseclass
class Item : public Action {
private:
	// Item count all items have
	int itemCount = 1;
	
public:
	// Constructor
	Item(Inventory* owningInv) : Action(owningInv) {
		setName("Item");
	}

	// Item baseclass will always subtract item count when used
	// Be sure to also call this for all Items --> Item::ExecuteAction()
	virtual void ExecuteAction() {
		itemCount -= 1;
	}
};


// Special Baseclass
class SpecialMagic : public Action {
private:


public:

	// Constructor
	SpecialMagic(Inventory* owningInv) : Action(owningInv) {
		setName("Special");
	}

	// Execution Override (empty...)
	virtual void ExecuteAction() {};
};


// ------------Specific Action Subclasses (Add new Actions below!)------------
class Attack : public Action {
private:
public:
	// Constructor
	Attack(Inventory* owningInv) : Action(owningInv) {
		setName("Attack");
		setPower(1);
	}

	// Execution Override (in .cpp)
	virtual void ExecuteAction();
};


// Mega Flare Attack
class MegaFlare : public Action {
private:
public:
	// Constructor
	MegaFlare(Inventory* owningInv) : Action(owningInv) {
		setName("Mega Flare");
		setPower(999);
	}

	// Execution Override (in .cpp)
	virtual void ExecuteAction();
};

// New Slash Attack
class NewSlashAttack : public Action {
private:
public:
	// Constructor
	NewSlashAttack(Inventory* owningInv) : Action(owningInv) {
		setName("Slash Attack");
		setPower(2);
	}

	// Execution Override (in .cpp)
	virtual void ExecuteAction();
};


//------------Enemy Specific Actions------------
// Slime Pounce Action Subclass
class SlimePounce : public Action {
private:


public:
	// Constructor
	SlimePounce(Inventory* owningInv) : Action(owningInv) {
		setName("SlimePounce");
		setPower(0.5);
	}

	// Execution Override (in .cpp)
	virtual void ExecuteAction();
};

#endif /* ACTION_H */