#include <stdio.h>
int main(void)
{
	double numf;

	printf("Please input a floating number:\n");
	scanf("%lf", &numf);
	printf("The input is %.1lf or %le\n", numf, numf);
	printf("The input is %.3lf or %lE\n", numf, numf);
	return 0;
}
