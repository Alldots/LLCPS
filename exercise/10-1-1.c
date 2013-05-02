int factorial(int n)
{
	if (n == 0)
		return 1;
	else if (n > 0)
		return n * factorial(n - 1);
}

int main(void)
{
	int i = factorial(3);

	return 0;
}
