#include "include/RandomNumbers.h"

float RandomNumbers::get_float(float start, float end)
{
    return 0.0;
}

int RandomNumbers::get_int(int start, int end)
{
	srand(time(NULL)+rand());
	
	int result = rand() % end;
	
	if (result < start) return RandomNumbers::get_int(start, end);
	else return rand() % end;
}