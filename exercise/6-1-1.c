#include <stdio.h>

int euclid(int a, int b)
{
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

int main(void)
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("euclid(%d, %d) = %d\n", a, b, euclid(a, b));

  return 0;
}
