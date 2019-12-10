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
		if (x == 0 && exp == 0)
		{
			printf("Zero to  power zero is undefined!\n");
			printf("Enter a number and the positive integer power");
                        printf(" to which\nthe number will be raised. Enter q");
                        printf(" to quit.\n");
			continue;
		}
		printf("%.3g to the power %d is %.5g\n", x, (int) exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoed this power trip -- bye!\n");
	return 0;
}

/*double power(double n, double p)
{
	double pow = 1;
	double temp = 1;
	int i;
	if (p > 0)
	{
		for (i = 1; i <= (int) p; i++)
			pow *= n;
	}
	else if (p < 0)
	{
		for (i = 1; i <= (int) p * (-1); i++)
			temp *=	n;
			pow = 1 / temp;
	}
	else
		if (n != 0)
			pow = 1;
	return pow;
}*/

double power(double n, double p)
{
	if (p == 1)
		return n;
	else if (p > 1)
		return n * power (n, (int)p - 1);
	else if (p == 0)
		return 1;
	else
		return 1 / (n * power(n, (-1 * (int)p) - 1));
}

