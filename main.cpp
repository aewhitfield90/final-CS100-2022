#include <iostream>
#include <string>
#include <stdlib.h>

#include "creature.h"

using namespace std;

int main()
{
	// Init vars
	vector<Creature> creatureTurnList;
	vector<Monster> EnemyList;

	Player playerChar("Ass", 100, 5);		// Create Player
	creatureTurnList.push_back(playerChar);	// Add to turn list

	Slime enmSlime_001("Slime 1");				// Create Slime enemy
	creatureTurnList.push_back(enmSlime_001);	// Add to turn list
	EnemyList.push_back(enmSlime_001);			// Add to enemy list

	// Do battle event
	cout << "A slimes stand in your way!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	

}

void CombatLoop(vector<Creature>& turnList, vector<Monster>& enemyList) {
	while (enemyList.size() > 1) {

	}
}