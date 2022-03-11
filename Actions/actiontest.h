#pragma once
#include "../googletest/googletest/include/gtest/gtest.h"
#include "Action.h"

TEST(ActionTest, CreateActionPotion) {
	Inventory* inv = new Inventory();
	Action* a1 = new Potion(inv);	

	EXPECT_TRUE(a1->getName() == "Potion");
	EXPECT_TRUE(a1->getPower() == 0.f);

	delete inv;
	delete a1;
}

TEST(ActionTest, CreateActionAttack) {
	Inventory* inv = new Inventory();
	Action* a1 = new Attack(inv);

	EXPECT_TRUE(a1->getName() == "Attack");
	EXPECT_TRUE(a1->getPower() == 1.f);

	delete inv;
	delete a1;
}

TEST(ActionTest, CreateActionMegaFlare) {
	Inventory* inv = new Inventory();
	Action* a1 = new MegaFlare(inv);

	EXPECT_TRUE(a1->getName() == "Mega Flare");
	EXPECT_TRUE(a1->getPower() == 999.f);

	delete a1;
	delete inv;
}

TEST(ActionTest, CreateActionHeal) {
	Inventory* inv = new Inventory();
	Action* a1 = new Heal(inv);

	EXPECT_TRUE(a1->getName() == "Heal");
	EXPECT_TRUE(a1->getPower() == 0.f);

	delete inv;
	delete a1;
}
