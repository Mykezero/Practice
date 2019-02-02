#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "fizzbuzz.h"
	#include "Console.h"
}

TEST_GROUP(FizzBuzz) { };

TEST(FizzBuzz, PrintsNumber)
{
	Run();
	char* message = GetLastMessage();
	STRCMP_CONTAINS_TEXT("1", message, "Fizz buzz should print numbers");
};


TEST(FizzBuzz, PrintsFizz)
{
	Run();
	char* message = GetLastMessage();
	STRCMP_CONTAINS("fizz", message);
};

TEST(FizzBuzz, PrintsBuzz)
{
	// Fixture setup
	// Exercise system
	Run();
	// Verify outcome
	char* message = GetLastMessage();
	STRCMP_CONTAINS("buzz", message);
	// Teardown
};