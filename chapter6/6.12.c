#include <stdio.h>
#define LEN 1000
int power_of_two(int);
int main(void)
{
	int num_array[LEN];
	int k = 0;

	num_array[0] = 1;
	for (int i = 1; i <= 8; i++)
		num_array[i] = power_of_two(i);
	do
	{
		printf("2^%d = %d\n", k, num_array[k]);
		k++;
	} while (k <= 8);
	return 0;
}

int power_of_two(int count)
{
	int val = 1;

	for (int i = 1; i <= count; i++)
		val *= 2;
	return val;
}
