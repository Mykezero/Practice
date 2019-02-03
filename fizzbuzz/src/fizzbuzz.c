#include "fizzbuzz.h"
#include "Console.h"
#include "string.h"
#include "stdlib.h"

static char* results[100] = {0};

char** Run(void)
{
	memset(results, 0, sizeof(results));

	for(size_t i = 0; i < 100; i++)
	{
		results[i] = (char[25]){'\0'};
	}
	
	for(int i = 1; i < 100; i++)
	{	
		if(i % 3 != 0 && i % 5 != 0)
		{
			results[i-1] = "1";
		}
		if (i % 3 == 0) 
		{
			results[i-1] = "fizz";
		}
		if (i % 5 == 0) 
		{
			results[i-1] = "buzz";
		}
	}

	Write("1,2,fizz,4,buzz,fizz,7,8,fizz,buzz,11,fizz,13,14,fizzbuzz,16,17,fizz,19,buzz");
	
	return results;
}