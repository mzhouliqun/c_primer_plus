#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *itobs(int, char *);
int bstoi(char *);
int open_count(int);

int main(void)
{
	int n;
	char bin_str[8 * sizeof(int) + 1];

	printf("Please enter an integer and the program will give you the number of open bits for this integer.\n");
	printf("\nYour integer is: ");
	while (scanf("%d", &n) == 1)
	{
		printf("Binary form: %s\n", itobs(n, bin_str));
		printf("The number of open bits: %d\n", open_count (n));
		printf("\nYour integer is: ");
	}
	printf("Quit.\n");
	return 0;
}

int open_count(int num)
{
	int count = 0;
	int mask = 1;

	while (num)
	{
		if (num & mask)
			count++;
		num >>=1;
	}
	return count;
}

char *itobs(int n, char *ps)
{
	int i;
	int size = 8 * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (1 & n) + '0';
	ps[size] = '\0';
	return ps;
}
