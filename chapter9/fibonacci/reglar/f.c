#include <stdio.h>
#include <stdlib.h>
int fibonacci(int );
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [Positive integer]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", fibonacci(atoi(argv[1])));
	return 0;
}

int fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int c;
	int index = 0;

	if (n < 0)
	{
		fprintf(stderr, "The term number must be positive integer.\n");
		exit(EXIT_FAILURE);
	}
	else if (n < 3)
		c = a;
	else
	{
		n -= 2;
		while (index < n)
		{
			c = a + b;
			a = b;
			b = c;
			index++;
		}
	}
	return c;
}
