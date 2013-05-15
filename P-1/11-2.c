#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

void merge(int start, int mid, int end)
{
	int l1 = mid - start + 1;
	int l2 = end - mid;
	int left[l1], right[l2];
	int i, j, pos;

	for (i = 0; i < l1; i++) {
		left[i] = a[start + i];
	}
	for (j = 0; j < l2; j++) {
		right[j] = a[mid + 1 + j];
	}

	i = j = 0;
	pos = start;

	while ((i < l1) && (j < l2)) {
		if (left[i] <= right[j]) {
			a[pos++] = left[i++];
		} else {
			a[pos++] = right[j++];
		}
	}
	while (i < l1) {
		a[pos++] = left[i++];
	}
	while (j < l2) {
		a[pos++] = right[j++];
	}
}
	
void sort(int start, int end)
{
	if (start >= end) {
		return;
	} else {
		int mid = (start + end) / 2;
		printf("sort(%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
			start, mid, mid + 1, end,
			a[0], a[1], a[2], a[3], a[4], a[5],a[6], a[7]); 
		sort(start, mid);
		sort(mid + 1, end);
		merge(start, mid, end);
		printf("merge(%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",
			start, mid, mid + 1, end,
			a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
		return;
	}
}

int main(void)
{
	sort(0, LEN - 1);
	return 0;
}
		
