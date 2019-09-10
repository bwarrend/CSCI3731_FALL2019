#include <cstdio>


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

  printf("Enter 2 integers:\n");
  scanf("%d %d", &a, &b);

  printf("a = %d\nb = %d\n", a, b);

  swapInts(&a, &b);
  printf("Swapped:\n");
  printf("a = %d\nb = %d\n", a, b);

  return 0;

}
