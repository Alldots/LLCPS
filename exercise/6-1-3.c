#include <stdio.h>

int main(void)
{
  int n = 1, count = 0;
  while (n < 100) {
    if (n / 10 == 9) {
      printf("%d\n", n);
      count++;
    }
    if (n % 10 == 9) {
      count++;
      printf("%d\n", n);
    }
    n++;
  }
  printf("Times of number 9 appeared: %d\n", count);

  return 0;
}
