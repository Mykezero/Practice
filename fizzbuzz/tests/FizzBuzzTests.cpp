#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "fizzbuzz.h"
	#include "Console.h"
}

TEST_GROUP(FizzBuzz) { };

TEST(FizzBuzz, PrintsNumber)
{
	STRCMP_CONTAINS_TEXT("1", Run()[0], "Prints Numbers");
};

TEST(FizzBuzz, PrintsFizz)
{
	STRCMP_CONTAINS_TEXT("fizz", Run()[2], "Prints Fizz");
};

TEST(FizzBuzz, PrintsBuzz)
{
	STRCMP_CONTAINS_TEXT("buzz", Run()[4], "Prints Buzz");
};