#include <stdio.h>
int main(void)
{
	int sum_odd = 0;
	int sum_even = 0;
	int count_odd = 0;
	int count_even = 0;
	int num;

	printf("Please enter a set of integers end by '0':\n");
	for(;;)
	{
		while (scanf("%d", &num) == 1 && num != 0)
		{
			if ((num % 2) == 0)
			{
				sum_even += num;
				count_even++;
			}
			else
			{
				sum_odd += num;
				count_odd++;
			}
			printf("Please continue to enter an integer, end by '0':\n");
		}
		while (getchar() != '\n')
			continue;
		if (num == 0)
			break;
	}
	if (count_odd != 0)
		printf("The count of odd is %d, the average value of odd is %lf\n", count_odd, ((double)sum_odd / (double)count_odd));
	else
		printf("The count of odd is %d, the average value of odd is %d\n", count_odd, 0);
	if (count_even != 0)
		printf("The count of even is %d, the average value of even is %lf\n", count_even, ((double)sum_even / (double)count_even));
	else
		printf("The count of odd is %d, the average value of odd is %d\n", count_even, 0);
	return 0;
}
