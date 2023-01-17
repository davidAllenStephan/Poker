#include <cstdlib>
int getRand(int upperBound)
{
	int randomNumber = (rand() % (upperBound + 1));
	return randomNumber;
}