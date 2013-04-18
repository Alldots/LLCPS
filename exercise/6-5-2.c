#include <stdio.h>

void diamond(int l, char c)
{
  if (l % 2 == 0) {
    printf("Even length is not allowed!\n");
    
    return;
  }

  int i, j, cPerLine;
  for (i = 1; i <= l; ++i) {
    for (j= 0; j < l; ++j) {
      cPerLine = 2*i -1;
      if (cPerLine <= l && (l - cPerLine) / 2 <= j && j < (l + cPerLine) / 2) 
        printf("%c\t", c);
      else if (cPerLine > l && (cPerLine - l) / 2 <= l - j - 1 && 
              l - j - 1 < (3*l - cPerLine)/2)
        printf("%c\t", c);
      else
        printf(" \t");
    }
    printf("\n");
  }
}

int main(void)
{
  diamond(3, '*');
  printf("\n\n\n\n");
  diamond(5, '+');
  printf("\n\n\n\n");
  diamond(9, '*');
  printf("\n\n\n\n");
  diamond(2, 'A');
      
  return 0;
}
