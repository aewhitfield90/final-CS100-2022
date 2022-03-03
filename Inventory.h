#ifndef INVENTORY_H
#define INVENTORY_H

#include "Actions/Action.h"

using namespace std;

class Inventory {
private:
	// Get lists of different actions that characters can do
	vector<Action*> actionList;	// General Action List when selecting commands to do
	vector<Item*> itemList;		// If selected to use items, then look in item list
	vector<SpecialMagic*> magicSpecialList;	// Or if selected magic, then look in magic

	// Get Owning Character
	class Creature* owner;

public:
	// Get variables
	vector<Action*>& getActionList()			{ return actionList; }
	vector<Item*>& getItemList()				{ return itemList; }
	vector<SpecialMagic*>& getSpecialMagic()	{ return magicSpecialList; }
	Creature* getCreatureOwner()				{ return owner; }

	// Set variables
	void setActionList(vector<Action*>& inList)			{ this->actionList = inList; }
	void setItemList(vector<Item*>& inList)				{ this->itemList = inList; }
	void setSpecialMagic(vector<SpecialMagic*>& inList)	{ this->magicSpecialList = inList; }
	void setCreatureOwner(Creature* owningCreature)		{ this->owner = owningCreature; }

	// Destructor
	~Inventory() {	// Clear inventory
		for (Action* i : actionList) {
			delete i;
		}
		for (Item* i : itemList) {
			delete i;
		}
		for (SpecialMagic* i : magicSpecialList) {
			delete i;
		}
	}
};

#endif /* INVENTORY_H */