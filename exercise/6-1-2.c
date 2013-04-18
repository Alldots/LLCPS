#include <stdio.h>

int fib(int n)
{
  int fn = 0, f = 1;
  while (n > 0) {
    fn = fn + f;
    f = fn - f;
    n = n - 1;
  }
  
  return fn;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  printf("fib(n) = %d\n", fib(n));

  return 0;
}
