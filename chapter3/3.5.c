#include <stdio.h>
int main(void)
{
	double a = 3.156E+7;
	double b;
	printf("Please input your age: \n");
	scanf("%lf", &b);
	printf("Your age is %le seconds\n", a * b);
	return 0;
}
