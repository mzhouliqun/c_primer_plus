#include <stdio.h>
int main(void)
{

	double num;
	printf("Please input a number\n");
	scanf("%lf", &num);
	if ((int)num == num )
		printf("%d is a integer.\n", (int)num);
	else
		printf("%lf is not a integer.\n", num);
	return 0;
}
