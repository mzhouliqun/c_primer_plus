#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"
int roll_count = 0;

static int rollem(int sides)
{
	int roll;

	roll = rand() % sides + 1;
	roll_count++;
	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;

	if (sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Need at least 1 die.\n");
		return -1;
	}
	for (d = 0; d < dice; d++)
		total += rollem(sides);
	return total;
}

int get_first_int(void)
{
        int n;
        char ch;

        while (scanf("%d", &n) != 1 || n < 0)
        {
                if (n < 0)
                        printf("%d", n);
                while ((ch = getchar()) != '\n')
                        putchar(ch);
                printf(" is not a non-negative.\n");
        }
        return n;
}
