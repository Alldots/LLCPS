#include <stdio.h>

void newline(void)
{
  printf("\n");
}

void threeline(void)
{
  newline();
  newline();
  newline();
}

int main(void)
{
  printf("Three line:\n");
  threeline();
  printf("Another three line.\n");
  threeline();
 
  return 0;
}
