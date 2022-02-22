
#include <string>

class Creature {
private:
	string name = "";
	int healthPoints = 0;
	int attackPoints = 0;
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
	void makePlayer(string n) {
		name = n;
		healthPoints = 100;
		attackPoints = 5;
	}
	int getXP() {
		return experiencePoints;
	}
};

class Monster : public Creature {
private:
	item loot = new item(rand());
};

class Slime : public Monster {
private:
	name = "Slime";
	Monster.health
public:
	setName("Slime");
	


};

class Rat : public Monster {
private:
	item loot = new item(rand());


};

class Skeleton : public Monster {
private:
	item loot = new item(rand());


};