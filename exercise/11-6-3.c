#include <stdio.h>

double mypow_recursion(double x, int n)
{
	if (n == 0) {
		return 1;
	} else {
		if (n % 2 == 0) {
			return (mypow_recursion(x, n / 2) * mypow_recursion(x, n / 2));
		} else {
			return (mypow_recursion(x, n / 2) * mypow_recursion(x, n / 2) * x); 
		}
	}
}

double mypow_loop(double x, int n)
{
	double product = 1;
	
	while (n > 0) {
		if (n % 2 == 1) {
			product = product * x;
		}
		x = x * x;
		n = n / 2;
	}

	return product;		
}

int main(void)
{
	printf("%f\n%f\n", mypow_recursion(2, 11), mypow_loop(2, 11));
	return 0;
}
