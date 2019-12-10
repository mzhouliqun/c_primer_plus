#include <stdio.h>
#include <stdbool.h>
#define MAXLEN 10
int search(int *, int, int);
int table[MAXLEN] = {1, 3, 5, 6, 9, 13, 19, 21, 34, 45};
int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		if (search(table, MAXLEN, i))
			printf("%d ", i);
	printf("\n");
	return 0;
}

int search(int table[], int max, int number)
{
	int half;
	int min = 0;

	if (max > 1)
		max--;
	for (;;)
	{
		half = (min + max) / 2;
		if (number > table[half])
			min = half + 1;
		else if (number < table[half])
			max = half;
		else
			return true;
		if (min == max)
		{
			if (number == table[min])
				return true;
			else
				return false;
		}
	}
}
