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

	Book* enmBook_001 = new Book("Book Mimic");
	Rat* enmRat_001 = new Rat("Stinky Rat");
	Slime* enmSlime_001 = new Slime("Slime");
	Imp* enmImp_001 = new Imp("Imp");
	Skeleton* enmSkeleton_001 = new Skeleton("Skeleton King");	// Create Slime enemy

	
	
	creatureTurnList.push_back(enmBook_001);	// Add to turn list
	EnemyList.push_back(enmBook_001);			// Add to enemy list

		//Dialogue Init vars
		Dialogue rm1("room1.txt");
		Dialogue rm2("room2.txt");
		Dialogue rm3("room3.txt");
		Dialogue rm4("room4.txt");
		Dialogue rm5("finalroom.txt");
		Dialogue outro("outro.txt");	

	// Set each creature's target for scenario
	enmBook_001->setTarget(playerChar);
	playerChar->setTarget(enmBook_001);
	
	//Print scene description
	cout << endl;
	rm1.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);
	
	// Do battle event
	cout << "A floating book flaps furiously before you!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);
	
	// Delete in the end
	delete enmBook_001;
	creatureTurnList.erase(creatureTurnList.begin() + 1);

	creatureTurnList.push_back(enmRat_001);	// Add to turn list
	EnemyList.push_back(enmRat_001);

	// Set each creature's target for scenario
	enmRat_001->setTarget(playerChar);
	playerChar->setTarget(enmRat_001);

	//Print scene description
	cout << endl;
	rm2.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	// Do battle event
	cout << "A large smelly rat skitters before you!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);

	// Delete in the end

	delete enmRat_001;
	creatureTurnList.erase(creatureTurnList.begin() + 1);

	creatureTurnList.push_back(enmSlime_001);	// Add to turn list
	EnemyList.push_back(enmSlime_001);

	// Set each creature's target for scenario
	enmSlime_001->setTarget(playerChar);
	playerChar->setTarget(enmSlime_001);

	//Print scene description
	cout << endl;
	rm3.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	// Do battle event
	cout << "A slime wiggles in your way!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);

	// Delete in the end

	delete enmSlime_001;
	creatureTurnList.erase(creatureTurnList.begin() + 1);

	creatureTurnList.push_back(enmImp_001);	// Add to turn list
	EnemyList.push_back(enmImp_001);

	// Set each creature's target for scenario
	enmImp_001->setTarget(playerChar);
	playerChar->setTarget(enmImp_001);

	//Print scene description
	cout << endl;
	rm4.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	// Do battle event
	cout << "A grinning imp fidgets before you!!!" << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);

	// Delete in the end

	delete enmImp_001;
	creatureTurnList.erase(creatureTurnList.begin() + 1);

	creatureTurnList.push_back(enmSkeleton_001);	// Add to turn list
	EnemyList.push_back(enmSkeleton_001);

	// Set each creature's target for scenario
	enmSkeleton_001->setTarget(playerChar);
	playerChar->setTarget(enmSkeleton_001);

	//Print scene description
	cout << endl;
	rm5.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	// Do battle event
	cout << "The Skeleton stands foreboding before you..." << endl;
	// Sleep for 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Do battle...
	CombatLoop(creatureTurnList, EnemyList);


	delete enmSkeleton_001;
	creatureTurnList.clear();

	cout << endl;
	outro.printDialogue(cout);
	cout << endl;
	PressToContinue(pTC);

	delete playerChar;

	//book rats slime imp skeleton
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
