#include <stdio.h>
int cal(int, int);
int main(void)
{
	int lower = 0;
	int upper = 0;

	printf("Enter lower and upper integer limits:\n");
	scanf("%d %d", &lower, &upper);
	while ((upper - lower) > 0)
	{
		printf("The sums of the squares from lower to upper is %d\n", cal(lower, upper));
		printf("Enter lower and upper integer limits(when upper is less than or equal to lower to quit):\n");
		scanf("%d %d", &lower, &upper);
	}
	return 0;
}

int cal(int l, int u)
{
	int sum = 0;

	for (int i = l; i <= u; i++)
		sum += i * i;
	return sum;
}
