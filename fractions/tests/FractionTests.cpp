#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "fractions.h"
}

TEST_GROUP(Fractions){ };

TEST(Fractions, ZeroPlusZero)
{
	Fraction one = create_fraction(1,1);
	Fraction other = create_fraction(1,1);
	Fraction result = add_fraction(one, other);
	CHECK_EQUAL_TEXT(2, result.int_value, "zero plus zero is 0")
};