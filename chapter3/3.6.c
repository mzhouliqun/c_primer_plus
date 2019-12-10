#include <stdio.h>
int main(void)
{
	double a = 3.0E-23;
	double b;

	printf("Please input how much quarts the water is: ");
	scanf("%lf", &b);
	printf("%lf quarts water has %le molecules.\n", b, b * 950 / a);
	return 0;
}
