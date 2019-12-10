#include <stdio.h>
int main(void)
{
	int a = 1;
	int b = 2147483646;
	int c = 2147483647;
	float d = 3.4E+38;
	float e = 0.1234E-9;
	int m = 10000000;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("a + b = %d\n", a + b);
	printf("a + c = %d\n", a + c);
	printf("d = %f\n", d);
	printf("d * 10 = %f\n", d * 10);
	printf("e = %.14f\n", e);
	printf("m = %d\n", m);
	printf("e / m = %.14f\n", e / m);
	return 0;
}
