#include <stdio.h>
int square(int);
int main(void)
{
	int count = 0;
	int sum = 0;
	int max = 0;

	printf("Please enter the sum serial number:\n");
	scanf("%d", &max);
	while (count++ < max)
		sum += square(count);
	printf("The sum of squares of the first %d terms makes %d.\n", max, sum);
	return 0;
}

int square(int n)
{
	return n * n;
}
