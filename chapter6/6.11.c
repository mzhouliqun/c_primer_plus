#include <stdio.h>
int positive_or_negative(int);
double sequence1(int);
double sequence2(int);
int main(void)
{
	int len;
	printf("Please enter the number of items in the sequence you want to calculate:\n");
	while (scanf("%d", &len) != 1)
		while (getchar() != '\n')
			continue;
	printf("\n");
	printf("len = %d:\n", len);
	printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... = %lf\n", sequence1(len));
	printf("\n");
	printf("len = %d:\n", len);
	printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... = %lf\n", sequence2(len));
	return 0;
}

int positive_or_negative(int n)
{
	int i = n % 2;
	int j = i + 1;
	int pon = 1;

	for (int k = 0; k < j; k++)
		pon *= -1;
	return pon;
}

double sequence1(int len)
{
	double sum = 0.0;

	for (int i = 1; i <= len; i++)
		sum += 1.0 / (double)i;
	return sum;
}

double sequence2(int len)
{
	double sum = 0.0;

	for (int i = 1; i <= len; i++)
		sum += (1.0 / (double)i) * positive_or_negative(i);
	return sum;
}
