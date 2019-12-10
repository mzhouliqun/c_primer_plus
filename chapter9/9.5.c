#include <stdio.h>
double getdouble(void);
void large_of(double *, double *);
int main(void)
{

	double numa, numb;

	printf("Please input two numbers:\n");
	printf("First number:\n");
	numa = getdouble();
	printf("Second number:\n");
	numb = getdouble();
	large_of(&numa, &numb);
	printf("Replace result is :\n");
	printf("First number is %lf.\n", numa);
	printf("Second number is %lf.\n", numb);
	return 0;
}

double getdouble(void)
{
	double number;
	while (scanf("%lf", &number) != 1)
	{
		printf("Input error, please try again!\n");
		scanf("%*s");
		continue;
	}
	return number;
}

void large_of(double *x, double *y)
{
	*x = *y = *x > *y ? *x : *y;
}
