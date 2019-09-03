#include <cstdio>
#include <stdlib.h>

//Returns an random int between a and b
int rRange(int a, int b){
	//Returns random number modulos the range + 1, then add
	//the min, which is a
	return (rand() % (b-(a-1))) + a;
}

//Prints Hello World horizontal if x > 5, else prints it vertically
void printHW(int x){
	if (x > 5)
	{
		printf("#%d\nHello World\n", x);
	}
	else
	{
		printf("#%d\nH\ne\nl\nl\no\n\nW\no\nr\nl\nd\n", x);
	}
}