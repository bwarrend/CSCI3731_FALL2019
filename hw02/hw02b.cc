#include <cstdio>
#include "bFunction.h"



int main(int argc, char** argv)
{
  int a;
  int b;
  //Get us some user ints.
  printf("Enter 2 integers:\n");
  scanf("%d %d", &a, &b);
  //This is what the user inputted in case they forgot.
  printf("a = %d\nb = %d\n", a, b);
  //Run our function with user input and re-print out the numbers.
  swapInts(&a, &b);
  printf("Swapped:\n");
  printf("a = %d\nb = %d\n", a, b);

  return 0;

}