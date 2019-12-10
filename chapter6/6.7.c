#include <stdio.h>
int main(void)
{
	double a;
	double b;

	printf("Please input two double-precision decimal:\n");
	while (scanf("%lf %lf", &a, &b) > 1)
	{
		printf("\na = %lf\n", a);
		printf("\nb = %lf\n\n", b);
		printf("(a - b) / (a * b) = %lf\n\n", (a - b) / (a * b));
		printf("Please input two double-precision decimal(non-numeric to quit):\n");
	}
	return 0;
}
