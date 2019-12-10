#include <stdio.h>
#define LEN 1000
int main(void)
{
	int i = 0;
	double sum = 0;
	double decimals[LEN];
	double array[LEN];

	printf("Please input 8 double-precision decimal:\n");
	while (i < 8)
	{
		printf("double-precision decimal_%d: ", i + 1);
		while (scanf("%lf", &decimals[i]) != 1)
			while (getchar() != '\n')
				continue;
		i++;
	}
	for (i = 0; i < 8; i++)
	{
		for (int j = 0; j <= i; j++)
			sum += decimals[j];
		array[i] = sum;
		sum = 0;
	}

	for (i = 0; i < 8; i++)
		printf("%.2lf\t", decimals[i]);
	printf("\n");
	for (i = 0; i < 8; i++)
		printf("%.2lf\t", array[i]);
	printf("\n");
	return 0;
}
