#include <string>
using namespace std;

class Creature {
private:
	string name;
	int healthPoints;
	int attackPoints;
public:
	void setName(string n) {
		name = n;
	}
	void setHP(int i) {
		healthPoints = i;
	}
	void setAP(int i) {
		attackPoints = i;
	}
	string getName() {
		return name;
	}
	int getHP() {
		return healthPoints;
	}
	int getAP() {
		return attackPoints;
	}
};

class Player : public Creature {
private:
	int experiencePoints = 0;
	//Item *inventoryArray = new Item[5]; //item array of item objects size 5
public:
	Player(string n) {//first time character creation stats
		setName(n);
		setHP(100);
		setAP(5);
	}
	int getXP() {
		return experiencePoints;
	}
	void getPlayerStats() {
		cout << "Character " << getName() << " stats:" << endl;
		cout << "Health Points: " << getHP() << endl;
		cout << "Attack Points: " << getAP() << endl;
		cout << "Experience Points: " << getXP() << endl << endl;
	}
};

class Monster : public Creature {
private:
	int loot = rand() % 100 + 1; //have to wait for loot class to be made
	int getLoot() {
		return loot; //place holder till loot class is finished
	}
};

class Slime : public Monster {
private:
public:
	Slime() {
		setName("Slime");
		setHP(25);
		setAP(3);
	}
};

class Rat : public Monster {
private:
public:
	Rat() {
		setName("Rat");
		setHP(15);
		setAP(2);
	}
};

class Skeleton : public Monster {
private:
public:
	Skeleton() {
		setName("Skeleton");
		setHP(40);
		setAP(5);
	}
};