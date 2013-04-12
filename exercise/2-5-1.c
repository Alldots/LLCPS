#include <stdio.h>

/*
 * x,n are positive integers, we know that answer of x/n is floor of division,
 * how to get the ceiling answer.
 * (x + n - 1) / n
 */

int main(void)
{
  int x = 17;
  int n = 4;
  printf("%d / %d = %d\n", x, n, (x + n - 1) / n);
  
  x = 16;
  n = 4;
  printf("%d / %d = %d\n", x, n, (x + n - 1) / n);

  return 0;
}
