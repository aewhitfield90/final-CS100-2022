#pragma once
#include "googletest/googletest/include/gtest/gtest.h"
#include "creature.h"

TEST(Monster, ConstructorWorks) {
	Book* temp = new Book("Moby Dick");
	int health = 5;
	int attack = 5;

	EXPECT_EQ(attack, temp->getAttack());	
	EXPECT_EQ(health, temp->getHealth());

	delete temp;
}


TEST(Monster, ChangeObject) {
	Book* temp = new Book("Moby Dick");
	string name = "Dune";
	int health = 4;
	int attack = 12;

	temp->setName(name);
	temp->setAttack(attack);
	temp->setHealth(health);
	
	EXPECT_EQ(name, temp->getName());
	EXPECT_EQ(attack, temp->getAttack());	
	EXPECT_EQ(health, temp->getHealth());

	delete temp;
}

