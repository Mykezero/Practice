#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "Bowling.h"
}

TEST_GROUP(Bowling){ };

TEST(Bowling, TestGutterGame)
{
	// Fixture setup
	init_game();
	// Exercise system
	for(size_t i = 0; i < 20; i++)
	{
		roll(0);
	}	
	// Verify outcome
	CHECK_EQUAL(0, score())
	// Teardown
};

TEST(Bowling, TestOnesGame)
{
	// Fixture setup
	init_game();
	// Exercise system
	for(size_t i = 0; i < 20; i++)
	{
		roll(1);
	}
	// Verify outcome
	CHECK_EQUAL(20, score());
	// Teardown
};