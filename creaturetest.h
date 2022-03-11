#pragma once
#include "googletest/googletest/include/gtest/gtest.h"
#include "creature.h"

TEST(CreatureTest, CreatePlayer) {
	Creature* a1 = new Player("Anime", 100, 100);

	EXPECT_TRUE(a1->getName() == "Anime");
	EXPECT_TRUE(a1->getAttack() == 100);
	EXPECT_TRUE(a1->getHealth() == 100);

	delete a1;
}

TEST(CreatureTest, CreatePlayerWithEmptyInventory) {
	Creature* a1 = new Player("Anime", 100, 100);

	EXPECT_TRUE(a1->getInventory()->getActionList().size() == 5);
	EXPECT_TRUE(a1->getInventory()->getItemList().size() == 0);
	EXPECT_TRUE(a1->getInventory()->getSpecialMagic().size() == 0);

	delete a1;
}

TEST(CreatureTest, EnemyRandomAttackBoundsTest) {
	srand(time(0));

	Creature* a1 = new Slime("Slimemoid");
	Creature* a2 = new Slime("Slimemooo");
	a2->setHealth(0);

	a1->setTarget(a2);
	a2->setTarget(a1);

	a1->CreatureTurn();

	// Basically only check if program would crash with this basic creature turn demonstration...
	EXPECT_TRUE(1 == 1);

	delete a1;
	delete a2;
}

TEST(CreatureTest, CreateMonster) {
	Creature* a1 = new Slime("Slimeme");

	EXPECT_TRUE(a1->getName() == "Slimeme");
	EXPECT_TRUE(a1->getAttack() == 3);
	EXPECT_TRUE(a1->getHealth() == 20);

	delete a1;
}