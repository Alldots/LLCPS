#include <stdio.h>

int euclid(int a, int b)
{
  int c;
  while (a % b != 0) {
    c = a;
    a = b;
    b = c % b;
  }

  return b;
}

int main(void)
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("euclid(%d, %d) = %d\n", a, b, euclid(a, b));

  return 0;
}
