#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "Bowling.h"
}

void roll_many(size_t rolls, int32_t pins)
{
	for(size_t i = 0; i < rolls; i++)
	{
		roll(pins);
	}
}

void roll_spare()
{
	roll(5);
	roll(5);
}

TEST_GROUP(Bowling)
{  
	void setup()
	{
		init_game();
	}
};

TEST(Bowling, TestGutterGame)
{
	// Fixture setup
	// Exercise system
	roll_many(20, 0);
	// Verify outcome
	CHECK_EQUAL(0, score())
	// Teardown
};

TEST(Bowling, TestOnesGame)
{
	// Fixture setup
	// Exercise system
	roll_many(20, 1);
	// Verify outcome
	CHECK_EQUAL(20, score());
	// Teardown
};

TEST(Bowling, TestSpareGame)
{
	// Fixture setup
	// Exercise system
	roll_spare();
	roll(3);
	roll_many(17, 0);
	// Verify outcome
	CHECK_EQUAL(16, score());
	// Teardown
};

TEST(Bowling, TestStrikeGame)
{
	// Fixture setup
	// Exercise system
	roll(10);
	roll(3);
	roll(4);
	roll_many(16, 0);
	// Verify outcome
	CHECK_EQUAL(24, score());
	// Teardown
};

TEST(Bowling, TestPerfectGame)
{
	// Fixture setup
	// Exercise system
	roll_many(12, 10);
	// Verify outcome
	CHECK_EQUAL(300, score());
	// Teardown
};