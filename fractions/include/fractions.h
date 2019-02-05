#include <stdint.h>

struct Fraction {
	int32_t one;
	int32_t other;
	int32_t int_value;
};

struct Fraction create_fraction(int32_t one, int32_t other);

struct Fraction add_fraction(struct Fraction one, struct Fraction other);