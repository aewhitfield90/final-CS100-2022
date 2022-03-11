#include "dialoguetest.h"
#include "test.h"
#include "inventorytest.h"
#include "Actions/actiontest.h"
#include "creaturetest.h"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
