#include <iostream>
#include <string>
#include "creature.cpp"
using namespace std;

int main{//tester main for classes
	cout << "Welcome to Text RPG" << endl;//dafsfasdf
	cout << "Creating Player 1" << endl;//dafsfasdf
	Player player1 = new Player("Tester");
	cout << "Player 1 stats:" << endl;
	cout << "Name: " + player1.getName() << endl;
	cout << "Health Points: " + player1.getHP() << endl;
	cout << "Attack Points: " + player1.getAP() << endl;
	
}