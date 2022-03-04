#include <iostream>
#include <string>
#include "creature.cpp"
using namespace std;

int main() {//tester main for classes
	cout << "Welcome to Text RPG" << endl;//dafsfasdf
	cout << "Creating Player 1" << endl;//dafsfasdf
	Player player1("Tester", 100, 5);

	player1.getPlayerStats();

	cout << "Changing " << player1.getName() << " name to Steve" << endl << endl;
	player1.setName("Steve");


	player1.getPlayerStats();

	return 0;
}

