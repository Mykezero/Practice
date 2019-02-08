#include "Bowling.h"

int32_t _scores[21];
int32_t currentRoll;

void init_game(void)
{
	for(size_t i = 0; i < 21; i++)
	{
		_scores[i] = 0;
	}

	currentRoll = 0;
}

void roll(int32_t pins)
{
	_scores[currentRoll++] += pins;
}

bool IsSpare(int32_t frame)
{
	return _scores[frame] + _scores[frame+1] == 10;
}

int32_t score(void)
{
	int32_t score = 0;
	int32_t frame = 0;

	for(size_t i = 0; i < 10; i++)
	{
		if(IsSpare(frame))
		{
			score += 10 + _scores[frame+2];
			frame+=2;
		}
		else
		{
			score += _scores[frame] + _scores[frame+1];
			frame+=2;
		}
	}

	return score;	
}