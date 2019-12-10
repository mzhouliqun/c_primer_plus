#include <stdio.h>
#define PARAMETER_M 1.609
#define PARAMETER_G 3.785
//#define PARAMETER_G 4.546
#define CONSTANT 100
int main(void)
{
	double m;
	double g;

	printf("Please input miles traveled:\n");
	scanf("%lf", &m);
	printf("Please input gallons of gas consumed:\n");
	scanf("%lf", &g);
	printf("It gets %.3lf miles per gallon\n", m / g);
	printf("It takes %.3lf litres of petrol to travel 100 kilometres\n", (g * PARAMETER_G * CONSTANT) / (m * PARAMETER_M));
	return 0;
}

