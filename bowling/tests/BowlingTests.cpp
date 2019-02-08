#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "Bowling.h"
}

TEST_GROUP(Bowling){ };

TEST(Bowling, TestGutterGame)
{
	// Fixture setup
	// Exercise system
	for(size_t i = 0; i < 21; i++)
	{
		roll(0);
	}
	
	// Verify outcome
	CHECK_EQUAL(0, score())
	// Teardown
};