#include <stdio.h>
void calculate(int);
int main(void)
{
	calculate(5);
	return 0;
}

void calculate(int n)
{
	int i = 1;

	while (n <= 150)
	{
		printf("Weeks: %d\n", i);
		printf("Number of friend: %d\n\n", n = (n - 1) * 2);
		i++;
	}
}
