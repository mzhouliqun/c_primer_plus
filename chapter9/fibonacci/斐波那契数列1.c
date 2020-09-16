#include <stdio.h>
unsigned long long Fibonacci(unsigned long long);
int main(void)
{
	unsigned long long n;
	printf("Enter an integer (q to quit):\n");
	while (scanf("%llu", &n) == 1)
	{
		printf("The term %llu of Fibonacci sequence is %llu\n", n, Fibonacci (n));
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}

unsigned long long Fibonacci(unsigned long long n)
{
	unsigned long long n1,n2,temp,i;
	if (n >2)
	for (n1=1,n2=1,i=3; i<=n; i++)
	{
		temp = n1 + n2;
		n1 = n2;
		n2 = temp;
	}
		else n2=1;
 		return n2;
}

