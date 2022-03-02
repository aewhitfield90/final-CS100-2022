#ifndef ACTION_H
#define ACTION_H
#include <string>

using namespace std;

// Action Baseclass/Interface
class Action {
private:
	// Create Vars
	int power = 0;						// The Action's general power
    string name = "Action";				// Action's name
	class Inventory* owningInventory;	// Action's owning inventory

public:
	// Get Functions
	string getName()				{ return name; }
	Inventory* getOwningInventory() { return owningInventory; }

	// Set Functions
	void setOwningInventory(Inventory* inventory) { this->owningInventory = inventory; }
	void setName(string inName) { this->name = inName; }

	// Execute Action
	virtual void ExecuteAction() = 0;
};


// Item Baseclass
class Item : public Action {
private:
	// Item count all items have
	int itemCount = 1;
	
public:
	// Constructor
	Item() {
		setName("Item");
	}

	// Item baseclass will always subtract item count when used
	// Be sure to also call this for all Items --> Item::ExecuteAction()
	virtual void ExecuteAction() {
		itemCount -= 1;
	}
};


// Attack Action Subclass
class Attack : public Action {
private:


public:
	// Constructor
	Attack() { 
		setName("Attack");
	}

	// Execution Override (in .cpp)
	virtual void ExecuteAction();
};


class SpecialMagic : public Action {
private:


public:

	// Constructor
	SpecialMagic() {
		setName("Special");
	}

	// Execution Override (empty...)
	virtual void ExecuteAction() {};
};

#endif /* ACTION_H */