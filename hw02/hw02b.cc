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
