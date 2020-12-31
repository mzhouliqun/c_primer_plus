#include <stdio.h>
#include <stdlib.h>
int get_value(void);
int check_value(int a);
void calculate(int, int);
int main(void)
{
	int divisor;
	int dividend;

	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	if (check_value(divisor = get_value()) == 0)
	{
		printf("Done!\n");
		exit(0);
	}
	printf("Now enter the first operand: ");
	if (check_value(dividend = get_value()) == 0)
	{
		printf("Done!\n");
		exit(0);
	}
	calculate(dividend, divisor);
	for (;;)
	{
		printf("Enter next number for first operand (<= 0 to quit): ");
		if (check_value(dividend = get_value()) == 0)
		{
			printf("Done!\n");
			exit(0);
		}
		calculate(dividend, divisor);
	}
	return 0;
}

int get_value(void)
{
	char ch;
	int n = 0;

	while (scanf("%d", &n) != 1)
	{
		if (ch = getchar() == EOF)
		{
			while (ch == EOF)
				ch = getchar();
			break;
		}
		while (ch != '\n' && ch != EOF)
			ch = getchar();
	}
	return n;
}

int check_value(int a)
{
	if (a <= 0)
		return 0;
	else
		return 1;
}

void calculate(int m, int n)
{
	printf("%d %% %d is %d\n", m, n, m % n);
}
