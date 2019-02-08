#include "Bowling.h"

int32_t _score;

void init_game(void)
{
	_score = 0;
}

void roll(int32_t pins)
{
	_score += pins;
}

int32_t score(void)
{
	return _score;
}