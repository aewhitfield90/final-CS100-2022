#include "Action.h"
#include "../creature.h"


//--------------Action general stuff--------------
// 
Action::Action(Inventory* owningInv) {
	// Set our inventory owner
	owningInventory = owningInv;

	// Get our owning creature from the inventory
	ownerCreature = getOwningInventory()->getCreatureOwner();
}


// Modify Health function for the owning creature (Used for healing or taking damage to self)
void Action::ModifyOwnerHealth(int damageAmt) {
	getOwnerCreature()->setHealth(getOwnerCreature()->getHealth() + damageAmt);
}


// Deal damage to owner creature's current target
int Action::DealDamageToTarget() {
	// Calculate our damage
	//(Damage is calculated from Creature Attack * Action's power)
	int damageAmt= static_cast<float>(getOwnerCreature()->getAttack())* getPower();

	// Deal that damage to the target
	Creature* target = getOwnerCreature()->getTarget();
	target->TakeDamage(damageAmt);

	return damageAmt;
}


//--------------Action subclasses (Add new Actions below!)--------------
// 
// Attack Action Execution
void Attack::ExecuteAction() {

	// Deal damage to Creature Target
	int damage = DealDamageToTarget();

	// Print that we dealt damage
	cout << getOwnerCreature()->getName() << " attacks!! Dealing <" << damage << "> to " << getOwnerCreature()->getTarget()->getName();
	cout << endl;

	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


// Slime Pounce Action Execution
void SlimePounce::ExecuteAction()
{
	// Deal damage to Creature Target
	int damage = DealDamageToTarget();

	// Print that we dealt damage
	cout << getOwnerCreature()->getName() << " throws itself, and pouncing!! Dealing <" << damage << "> to " << getOwnerCreature()->getTarget()->getName();
	cout << endl;

	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


// Mega Flare Action Execution
void MegaFlare::ExecuteAction()
{
	// Deal damage to Creature Target
	int damage = DealDamageToTarget();

	// Print that we dealt damage
	cout << getOwnerCreature()->getName() << " casts MEGA FLARE!! Dealing <" << damage << "> to " << getOwnerCreature()->getTarget()->getName();
	cout << endl;

	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
