#include <stdio.h>
double power(double n, double p);
int main(void)
{

	double x, xpow;
	double exp;

	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf("%lf%lf", &x, &exp) == 2)
	{
		if ((int)exp != exp)
		{
			printf("%lf is not a integer, please input again.\n", exp);
			printf("Enter a number and the positive integer power");
        		printf(" to which\nthe number will be raised. Enter q");
        		printf(" to quit.\n");
			continue;
		}
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, (int) exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoed this power trip -- bye!\n");
	return 0;
}

double power(double n, double p)
{
	double pow = 1;
	int i;

	for (i = 1; i <= (int) p; i++)
		pow *= n;
	return pow;
}
