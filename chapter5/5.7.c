#include <stdio.h>
double cube(double);
int main(void)
{
	double df;

	printf("Please input a double-precision decimal:\n");
	scanf("%lf",  &df);
	printf("%lf cubed is %lf\n", df, cube(df));
	return 0;
}
double cube(double x)
{
	return x * x * x;
}
