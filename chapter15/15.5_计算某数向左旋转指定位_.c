#include <stdio.h>
#define RANGE 32
unsigned int rotate_l(unsigned int, int);
int create_mask(int);
int main(void)
{
	unsigned int num;
	int len;

	printf("Please input a unsigned integer here:\n");
	while (scanf("%u", &num) != 1)
	{
		getchar();
		printf("\nInput error, try again!\n\n");
	}
	printf("Please input how many bits you want to rotate:\n");
	while(scanf("%d", &len) != 1 || len < 0 || len >= 32)
	{
		getchar();
		printf("\nThe range of left rotate should be at (0~31).\n");
		printf("Input error, try again!\n\n");
	}
	printf("%u reotate %d bits to left is: %u\n", num, len, rotate_l(num, len));
	return 0;
}

unsigned int rotate_l(unsigned int n, int l)
{
	int mask;
	unsigned int m;

	mask = create_mask(l);
	mask <<= (RANGE - l);
	m = n & mask;
	m >>= (RANGE - l);
	n &= ~mask;
	n <<= l;
	return(n + m);
}

int create_mask(int length)
{
	int mask = 0;
	int bit = 1;

	while (length-- > 0)
	{
		mask |= bit;
		bit <<= 1;
	}
	return mask;
}++

