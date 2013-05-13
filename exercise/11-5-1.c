#include <stdio.h>

#define LEN 5
int a[LEN] = { 10, 4, 5, 6, 12 };

int find_min(void)
{
	int min = 0;
	int i;

	for (i = 0; i < LEN; i++) {
		if (a[i] < a[min]) {
			min = i;
		}
	}
	return a[min];
}

int main(void)
{
	printf("min: %d - %d %d %d %d %d\n",
		find_min(), a[0], a[1], a[2], a[3], a[4]);
	return 0;
}
