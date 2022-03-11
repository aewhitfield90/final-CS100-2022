#include <iostream>
#include <string>
#include <stdlib.h>

#include "creature.h"
#include "dialogue.h"

using namespace std;

void CombatLoop(vector<Creature*>&, vector<Monster*>&);
void PressToContinue(string&);

int main()
{
	//INTRO!!
	string playerName = "Hero";
	string pTC;
	Dialogue intro("intro.txt");

	cout << "WELCOME ADVENTURER" << endl;
	cout << "Before proceeding please enter your name: ";

	cin >> playerName;
	
	cout << endl;
	cout << playerName << "..." << endl;
	intro.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	// Init vars
	vector<Creature*> creatureTurnList;
	vector<Monster*> EnemyList;

	Player* playerChar = new Player(playerName, 100, 5);		// Create Player
	creatureTurnList.push_back(playerChar);	// Add to turn list

	Slime* enmSlime_001 = new Slime("Slime 1");	// Create Slime enemy
	creatureTurnList.push_back(enmSlime_001);	// Add to turn list
	EnemyList.push_back(enmSlime_001);			// Add to enemy list

		//Dialogue Init vars
		Dialogue rm1("room1.txt");
		Dialogue rm2("room2.txt");
		Dialogue rm3("room3.txt");
		Dialogue rm4("room4.txt");
		Dialogue rm5("finalroom.txt");
		Dialogue outro("outro.txt");	

	// Set each creature's target for scenario
	enmSlime_001->setTarget(playerChar);
	playerChar->setTarget(enmSlime_001);
	
	//Print scene description
	cout << endl;
	rm3.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);
	
	// Do battle event
	cout << "A slime stands in your way!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);
	
	// Delete in the end
	delete enmSlime_001;
	

	Slime* enmSlime_002= new Slime("Slime 2");	// Create Slime enemy
	creatureTurnList.push_back(enmSlime_002);	// Add to turn list
	EnemyList.push_back(enmSlime_002);

	// Set each creature's target for scenario
	enmSlime_002->setTarget(playerChar);
	playerChar->setTarget(enmSlime_002);

	//Print scene description
	cout << endl;
	rm4.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	// Do battle event
	cout << "A slime stands in your way!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);

	
	//THE END
	cout << endl;
	outro.printDialogue(cout);
	cout << endl;

	// Delete in the end
	delete playerChar;
	delete enmSlime_002;
}

void CombatLoop(vector<Creature*>& turnList, vector<Monster*>& enemyList) {
	bool enemiesAlive = true;

	while (enemiesAlive) {
		// Do each creature turn
		for (Creature* creature : turnList) {
			if (creature) {
				if (creature->getHealth() > 0) {
					creature->CreatureTurn();
				}
			}
			cout << endl;
		}

		cout << endl;

		// Check if all enemies are alive, if not then end battle...could replace this later lol
		enemiesAlive = false;
		for (Monster* enemy : enemyList) {
			if (enemy->getHealth() > 0) enemiesAlive = true;
		}
	}
	cout << "VICTORY!!!" << endl;
}

void PressToContinue(string& press) {
	cout << "Press enter to continue...";
	press = cin.get();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
}
