#pragma once
#include "googletest/googletest/include/gtest/gtest.h"
#include "Inventory.h"
#include "Actions/Action.h"

TEST(InventoryTest, InventoryAddActions) {
	Inventory* temp = new Inventory();
	
	temp->getActionList().push_back(new Potion(temp));
	temp->getActionList().push_back(new Attack(temp));
	temp->getActionList().push_back(new MegaFlare(temp));

	string inv_str = "";

	for (Action* i : temp->getActionList()) {
		inv_str += i->getName() + " ";
	}

	EXPECT_TRUE(inv_str == "Potion Attack Mega Flare ");

	delete temp;
}

TEST(InventoryTest, InventoryNoActions) {
	Inventory* temp = new Inventory();

	string inv_str = "";

	for (Action* i : temp->getActionList()) {
		inv_str += i->getName() + " ";
	}

	EXPECT_TRUE(inv_str == "");

	delete temp;
}

TEST(InventoryTest, InventoryOnlyItems) {
	Inventory* temp = new Inventory();

	temp->getActionList().push_back(new Potion(temp));
	temp->getActionList().push_back(new Item(temp));
	temp->getActionList().push_back(new Item(temp));

	string inv_str = "";

	for (Action* i : temp->getActionList()) {
		inv_str += i->getName() + " ";
	}

	EXPECT_TRUE(inv_str == "Potion Item Item ");

	delete temp;
}