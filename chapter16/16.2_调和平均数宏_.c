#include <stdio.h>
#define HA(X, Y) (1 / (((1 / X) + (1 / Y)) / 2))
int main(void)
{
	double m, n;
	printf("Input two values, program will give their harmonic mean (double 0 to quit).\n\n");
	for (;;)
	{
		while (scanf("%lf %lf", &m, &n) != 2)
		{
			scanf("%*s");
			printf("\nInput error! Try again!\n\n");
		}
		if (m == 0 && n == 0)
		{
			printf("Quit.\n");
			break;
		}
		else if ((m + n) == 0 || m == 0 || n == 0)
			printf("\nInvalid arguments.\n\n");
		else
			printf("\nThe harmonic mean of %lf and %lf is %lf\n\n",m, n, HA(m, n));
		printf("Waiting for input (double 0 to quit):\n\n");
	}
	return 0;
}
