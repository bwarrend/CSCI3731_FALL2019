#include <cstdio>
#include "functions.h"

int main(int argc, char** argv)
{
	/*Run printHW function with a psuedo random number
	between 1 and 10*/
	printHW(rRange(1,10));
	return 0;
}