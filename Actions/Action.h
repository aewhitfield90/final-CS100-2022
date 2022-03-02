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

	virtual void ExecuteAction();
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

#endif /* ACTION_H */