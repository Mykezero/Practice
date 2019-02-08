#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "fizzbuzz.h"
	#include "Console.h"
}

TEST_GROUP(FizzBuzz) { };

TEST(FizzBuzz, PrintsNumber)
{
	STRCMP_EQUAL_TEXT("1", Run()[1], "Prints Numbers");
};

TEST(FizzBuzz, PrintsFizz)
{
	STRCMP_EQUAL_TEXT("fizz", Run()[2], "Prints Fizz");
};

TEST(FizzBuzz, With6PrintsFizz)
{
	STRCMP_EQUAL_TEXT("fizz", Run()[5], "Prints Fizz");
};

TEST(FizzBuzz, With9PrintsFizz)
{
	STRCMP_EQUAL_TEXT("fizz", Run()[8], "Prints Fizz");
};

TEST(FizzBuzz, PrintsBuzz)
{
	STRCMP_EQUAL_TEXT("buzz", Run()[4], "Prints Buzz");
};

TEST(FizzBuzz, With10PrintsBuzz)
{
	STRCMP_CONTAINS_TEXT("buzz", Run()[9], "Prints Buzz");
};

TEST(FizzBuzz, With15PrintsFizzBuzz)
{
	STRCMP_CONTAINS_TEXT("fizzbuzz", Run()[14], "Prints Buzz");
};

TEST(FizzBuzz, WritesFirst20NumbersToConsole)
{
	Run();
	char* actual = GetLastMessage();
	char* expected = (char*)"1,2,fizz,4,buzz,fizz,7,8,fizz,buzz,11,fizz,13,14,fizzbuzz,16,17,fizz,19,buzz";
	STRCMP_CONTAINS_TEXT(expected, actual, "Prints first 20 expected answers");
};