#include "Action.h"
#include "../creature.h"

// Attack Execution
void Attack::ExecuteAction() {
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