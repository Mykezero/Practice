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
	STRCMP_EQUAL_TEXT("1", message, "Fizz buzz should print numbers");
};


TEST(FizzBuzz, TEST)
{
	FAIL("This test is incomplete.")
};