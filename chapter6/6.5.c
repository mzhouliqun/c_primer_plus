#include <stdio.h>
int square(int);
int cube(int);
int main(void)
{
	int u_limit;
	int l_limit;

	printf("Please give an upper limit of an integer:\n");
	scanf("%d", &u_limit);
	printf("Please give a lower limit of an integer:\n");
	scanf("%d", &l_limit);
	printf("\n");
	printf("num\t\tsquare\t\tcube\n");
	for (int i = u_limit; i <= l_limit; i++)
		printf("%d\t\t%d\t\t%d\n", i, square(i), cube(i));
	return 0;
}

int square(int n)
{
	return  n * n;
}

int cube(int n)
{
	return n * n * n;
}
