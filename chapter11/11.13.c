#include <stdio.h>
#include <stdlib.h>
double power(double, int);
int main(int argc, char *argv[])
{
	double a;
	int b;
	if (argc > 3)
		puts("too many arguments to function 'main'");
	else if (argc < 3)
		puts("too few arguments to function 'main'");
	else
	{
		a = atof(*(argv + 1));
		b = atoi(*(argv + 2));
	}
		
	printf("%lf\n", power(a, b));
	return 0;
}

double power(double m, int n)
{
	int i;
	double power = 1;

	for (i = 0; i < n; i++)
		power *= m;
	return power;
}
