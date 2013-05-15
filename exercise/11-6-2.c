#include <stdio.h>

double mysqrt(double y)
{
	double start = 0, end = y, x = y / 2;

	while ((x*x - y > 0.001) || (y - x*x > 0.001)) {
		if (x*x > y) {
			end = x;
		} else if (x*x < y) {
			start = x;
		}
		x = (start + end) / 2;
	}

	return x;
}

int main(void) {
	printf("%f\n", mysqrt(5));
	return 0;
}
