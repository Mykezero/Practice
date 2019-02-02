#include "fizzbuzz.h"
#include "Console.h"

char* results[100];

char** Run(void)
{
	results[0] = "1";
	results[2] = "fizz";
	results[4] = "buzz";
	return results;
}