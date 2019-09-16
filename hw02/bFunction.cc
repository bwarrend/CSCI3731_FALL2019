#include <cstdio>

//Take two into pointers and swtich their int value,
//..value change occurs in memory so no return needed.
void swapInts(int* a, int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}