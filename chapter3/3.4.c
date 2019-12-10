#include <stdio.h>
int main(void)
{
	float f;

	printf("Please input a float number here: \n");
	scanf("%f", &f);
	printf("The input is %f or %e\n", f, f);
	return 0;
}
