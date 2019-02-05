#include "fractions.h"

struct Fraction create_fraction(int32_t one, int32_t other)
{
	struct Fraction fraction = { .one = one, .other = other };
	return fraction;
}

struct Fraction add_fraction(struct Fraction one, struct Fraction other)
{
	int dividend = one.one + other.one;
	int divisor = one.other;
	int int_value = dividend / divisor;
	struct Fraction fraction = { .one = dividend, .other = divisor, .int_value = int_value };
	return fraction;
}