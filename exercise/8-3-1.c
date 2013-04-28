#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];

void gen_random(int upper_bound)
{
  int i;
  
  for (i = 0; i < N; i++)
    a[i] = rand() % upper_bound;
}

int main(void)
{
  int i, histogram[10] = {0};
  
  gen_random(10);
  for (i = 0; i < N; i++)
    histogram[a[i]]++;
  
  int ifAll = 0,count = 0;
  printf("0 1 2 3 4 5 6 7 8 9\n\n");
  while (ifAll == 0) {
    ifAll = 1;
    for (i = 0; i < 10; i++) {
      if (count < histogram[i]) {
        ifAll = 0;
        printf("* ");
      } else
        printf("  ");
    }
    printf("\n");
    count++;
  }

  return 0;
}
    
    
    
