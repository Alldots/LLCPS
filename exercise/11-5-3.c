#include <stdio.h>

#define LEN 5
int a[LEN] = { 2, 5, 6, 23, 54 };

int partition(int start, int end)
{
	int pivot = start;
	int i = start + 1;
	int j = end;

	int tmp;
	while (1) {
		while (a[j] > a[pivot] && j >= i) {
			j--;
		}
		while (a[i] < a[pivot] && i < j) {
			i++;
		}
		if (j <= i) {
			break;
		}

		tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
	}
	tmp = a[j];
	a[j] = a[pivot];
	a[pivot] = tmp;

	return j;
}

int order_statistic(int start, int end, int k)
{
	int i = partition(start, end);
	if (k == i)
		return a[i];
	else if(k > i)
		order_statistic(i + 1, end, k - i);
	else
		order_statistic(start, i - 1, i - k);
}

int main(void)
{
	int k_min = order_statistic(0, LEN - 1, 3);
	int i;
	
	printf("k_min: %d\n", k_min);
	for (i = 0; i < LEN; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
