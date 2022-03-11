#pragma once
#include "googletest/googletest/include/gtest/gtest.h"
#include "dialogue.h"

TEST(Dialogue, ConstructorWorks) {
	Dialogue* temp = new Dialogue("test.txt");
	string tmpString = "dialogue/test.txt";
	
	EXPECT_TRUE(temp->GetFileName() == tmpString);

	delete temp;
}

TEST(Dialogue, DialoguePrints) {
	Dialogue* temp = new Dialogue("test.txt");
	string tmpString = "You open the dungeon door :O\n";

	ostringstream ss;
	temp->printDialogue(ss);
	string output = ss.str();

	EXPECT_EQ(output, tmpString);
}

