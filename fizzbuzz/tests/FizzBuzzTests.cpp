#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "fizzbuzz.h"
}

TEST_GROUP(FizzBuzz) { };

TEST(FizzBuzz, PrintsNumber)
{
	Run();
};
