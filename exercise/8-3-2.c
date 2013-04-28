#include <stdio.h>
#define N 6
#define M 3

int a[N] = { 1, 2, 3, 4, 5, 6 };
int b[M];
int count;

void all_arrangement(int start)
{
  int i;
  if (start == N - 1) {
    for (i = 0; i < N; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
    count++;
  } else if (start >= 0) {
    for (i = start; i < N; i++) {
      int tmp;
      tmp = a[start];
      a[start] = a[i];
      a[i] = tmp;
      all_arrangement(start + 1);
      tmp = a[start];
      a[start] = a[i];
      a[i] = tmp;
    }
  }
}

void arrangement(int start)
{
  int i;
  if (start == M) {
    for (i = 0; i < M; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
    count++;
  } else if (start >= 0) {
    for (i = start; i < N; i++) {
      int tmp = a[start];
      a[start] = a[i];
      a[i] = tmp;
      arrangement(start + 1);
      tmp = a[start];
      a[start] = a[i];
      a[i] = tmp;
    }
  }
}
     
void combination(int n, int m)
{
  int i;
  for (i = n; i >= m; i--) {
    b[m-1] = i-1;
    if (m > 1) {
      combination(i-1, m-1);
    }
    if (m == 1) {
      int j;
      for (j = 0; j < M; j++) {
        printf("%d ", a[b[j]]);
      }
      printf("\n");
      count++;
    }
  }
}

int main(void)
{
  combination(N, M);
  printf("\n\n%d\n", count);
  return 0;
}
