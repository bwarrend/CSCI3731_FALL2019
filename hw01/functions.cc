#include <cstdio>
#include <time.h>
#include <stdlib.h>

int rRange(int a, int b){
	srand(time(NULL));
	return (rand() % (b-(a-1))) + a;
}

void printHW(int x){
	if (x > 5)
	{
		printf("#%d\nHello World", x);
	}
	else
	{
		printf("#%d\nH\ne\nl\nl\no\n\nW\no\nr\nl\nd", x);
	}
}
