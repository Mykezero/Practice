#include "Bowling.h"
#include "string.h"

int32_t _scores[21];
int32_t currentRoll;

void init_game(void)
{
	memset(_scores, 0, sizeof(int32_t) * 21);
	currentRoll = 0;
}

void roll(int32_t pins)
{
	_scores[currentRoll++] += pins;
}

bool is_spare(int32_t frame)
{
	return _scores[frame] + _scores[frame+1] == 10;
}

bool is_strike(int32_t frame)
{
	return _scores[frame] == 10;
}

int32_t strike_bonus(int32_t frame)
{
	return _scores[frame + 1] + _scores[frame + 2];
}

int32_t spare_bonus(int32_t frame)
{
	return _scores[frame+2];
}

int32_t sum_of_balls_in_frame(int32_t frame)
{
	return _scores[frame] + _scores[frame+1];
}

int32_t score(void)
{
	int32_t score = 0;
	int32_t frame = 0;

	for(size_t i = 0; i < 10; i++)
	{
		if(is_strike(frame))
		{
			score+= 10 + strike_bonus(frame);
			frame++;
		}
		else if(is_spare(frame))
		{
			score += 10 + spare_bonus(frame);
			frame+=2;
		}
		else
		{
			score += sum_of_balls_in_frame(frame);
			frame+=2;
		}
	}

	return score;	
}