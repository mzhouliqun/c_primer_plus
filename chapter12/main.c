#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"
int main(void)
{
	int dice;
	int sides;
	int count;
	int i;

	srand((unsigned int) time(0));
	printf ("Enter the number of sets: enter q to stop.\n");
//	count = get_first_int();
	while (scanf("%d", &count) == 1)
	{
		scanf("%*c");
		printf("How many sides and how many dice?\n");
		sides = get_first_int();
		dice = get_first_int();
		printf("Here are %d sets of %d %d-sided throws.\n", count, dice, sides);
		for (i = 0; i < count; i++)
		{	
if ((i % 10) == 0)
				printf("\n");
			printf("%-7d", roll_n_dice(dice, sides));
		}
		printf("\n");
		printf("How many sets? Enter q to stop.\n");
	}
	return 0;
}
