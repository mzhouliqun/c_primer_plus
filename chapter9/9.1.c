#include <stdio.h>
double min(double, double);
int main(void)
{

	double na, nb;

	printf("This program is used to compare the size of floating numbers.\n");
	printf("please input first number: ");
	scanf("%lf", &na);
	printf("please intput second number: ");
	scanf("%lf", &nb);
	
	if (na == nb)
		printf("%lf and %lf are equal!\n", na, nb);
	else
		printf("The smaller of %lf and %lf is %lf\n", na, nb, min(na, nb));
	return 0;
}

double min(double j, double k)
{

	if (j < k)
		return j;
	else
		return k;
}
