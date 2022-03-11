#pragma once
#include "googletest/googletest/include/gtest/gtest.h"
#include "Actions/Action.h"

TEST(ActionTest, CreateActionPotion) {
	Action* a1 = new Potion(nullptr);

	EXPECT_TRUE(a1->getName() == "Potion");
	EXPECT_TRUE(a1->getPower() == 0.f);

	delete a1;
}

TEST(ActionTest, CreateActionAttack) {
	Action* a1 = new Attack(nullptr);

	EXPECT_TRUE(a1->getName() == "Attack");
	EXPECT_TRUE(a1->getPower() == 1.f);

	delete a1;
}

TEST(ActionTest, CreateActionMegaFlare) {
	Action* a1 = new MegaFlare(nullptr);

	EXPECT_TRUE(a1->getName() == "Mega Flare");
	EXPECT_TRUE(a1->getPower() == 999.f);

	delete a1;
}

TEST(ActionTest, CreateActionHeal) {
	Action* a1 = new Heal(nullptr);

	EXPECT_TRUE(a1->getName() == "Heal");
	EXPECT_TRUE(a1->getPower() == 0.f);

	delete a1;
}