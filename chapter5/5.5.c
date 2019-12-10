#include <stdio.h>
int main(void)
{
	int count = 0;
	int sum = 0;
	int max = 0;

	printf("Please enter the sum serial number:\n");
	scanf("%d", &max);
	while (count++ < max)
		sum += count;
	printf("The first %d terms add up to %d.\n", max, sum);
	return 0;
}
