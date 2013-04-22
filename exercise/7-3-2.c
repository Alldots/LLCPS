#include <stdio.h>

enum coordinate_type { RECTANGULAR = 1, POLAR };

int main(void)
{
  int RECTANGULAR;
  printf("%d %d\n", RECTANGULAR, POLAR);
  return 0;
}

/*
 * Result: 0 2
 * It is because of the declaration of RECTANGULAR in main, it substitutes the
 * declaration in global. As the local variables declared not initialized
 * have the same value on its space.
 */
