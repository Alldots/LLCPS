#include <stdio.h>

int main(void)
{
   int a[5] = { 2, 3, 5, 1, 2 }, b[5], i;
  
   for (i = 0; i < 5; i++)
     b[i] = a[i];

   return 0;
}
