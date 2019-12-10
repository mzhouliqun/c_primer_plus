#include <stdio.h>
void to_binary(unsigned long n, int p);
int main(void)
{

	int per;
	unsigned long number;
	printf("Enter an integer (q to quit): \n");
	while (scanf("%lu%d", &number, &per) == 2)
	{
		printf("Binary equivalent: ");
		to_binary(number, per);
		putchar('\n');
		printf("Enter an integer (q to quit): \n");
	}
	printf("Done.\n");
	return 0;
}

void to_binary(unsigned long n, int p)
{
	int r;
	r = n % p;
	if (n >= p)
		to_binary(n / p, p);
	putchar('0' + r);
}
