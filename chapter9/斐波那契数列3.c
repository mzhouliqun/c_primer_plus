#include <stdio.h>
#include <stdlib.h>
int a[10001][5001] = {0};
int b[10001][5001] = {0};
int c[10001][5001] = {0};
int n;
int main(void)
{

	int i, j, k;

	printf("This program is used to calculate the term of the Fibonacci sequence.\n");
	printf("Enter an integer (q to quit): ");
	while (scanf("%d", &n) != 1)
		exit(0);
	printf("\n");
	for (k=1; k<=n; k++)
	{
		if (k < 3)
		{
			if (k == 1)
				printf("Fibonacci series 1:\n%d\n\n", 1);
			else
				printf("Fibonacci series 2:\n%d\n\n", 1);
		}
		else if (k == 3)
			printf("Fibonacci series 3:\n%d\n\n", 2);
		else
		{
			c[k][1] = 2;
			b[k][1] = 1;
			for (i = 1; i<= k - 3; i++)
			{
				for (j = 1; j <= 3000; j++)
				{
					a[k][j] = b[k][j];
					b[k][j] = c[k][j];
					c[k][j] = 0;
				}
				for (j=1; j <= 3000; j++)
				{
					c[k][j] = c[k][j] + a[k][j] + b[k][j];
					if (c[k][j] >= 10)
					{
						c[k][j] = c[k][j] - 10;
						c[k][j + 1] = 1;
					}
				}
			}
			i = 3000;
			while ( c[k][i] == 0)
				i--;
			printf("Fibonacci series %d:\n", k);
			for (i = i; i >= 1; i--)
				printf("%d", c[k][i]);
			printf("\n\n");
		}
	}
	return 0;
}
