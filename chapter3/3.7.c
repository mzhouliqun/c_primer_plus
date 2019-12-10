#include <stdio.h>
int main(void)
{
	double h;

	printf("What is your height in centimeters?\n");
	scanf("%lf", &h);
	printf("Your height is %.2lf inches.\n", h / 2.54);
	return 0;
}
