#include <cstdio>
#include "functions.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	
	//Seeds the RNG with the time
	srand(time(NULL));
	
	/*Run printHW function with a psuedo random number
	between 1 and 10*/	
	printHW(rRange(1,10));
	
	return 0;
}