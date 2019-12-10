#include <stdio.h>
double cal(double a, double b);
int main(void)
{
	double a;
	double b;

	printf("Please input two double-precision decimal:\n");
	while (scanf("%lf %lf", &a, &b) > 1)
	{
		printf("\na = %lf\n", a);
		printf("\nb = %lf\n\n", b);
		printf("(a - b) / (a * b) = %lf\n\n", cal(a, b));
		printf("Please input two double-precision decimal(non-numeric to quit):\n");
	}
	return 0;
}

double cal(double a, double b)
{
	return (a - b) / (a * b);
}
