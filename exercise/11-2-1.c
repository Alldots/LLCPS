#include <stdio.h>

#define LEN 10
int a[LEN] = { 1, 3, 5, 10, 289, 3, 5, 12, 2, 8 };

int partition(int start, int end)
{
	int pivot = a[start];
	int i, j, mid;
	int tmp;

	i = start + 1;
	j = end;
	while (1) {
		while (a[j] > pivot && j >= i) {
			j--;
		}
		while (a[i] < pivot && i < j) {
			i++;
		}
		if (j <= i) {
			break;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;

	}
	mid = j;
	tmp = a[mid];
	a[mid] = a[start];
	a[start] = tmp;

	return mid;
}

void quicksort(int start, int end)
{
	if (start >= end) {
		return;
	} else {
		int mid = partition(start, end);
		printf("quicksort(%d-%d, %d-%d) %d %d %d %d %d %d %d %d %d %d\n",
			start, mid - 1, mid + 1, end,
			a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]); 
		quicksort(start, mid - 1);
		quicksort(mid + 1, end);
	}
}
 
int main(void)
{
	quicksort(0, LEN - 1);
	return 0;
}
