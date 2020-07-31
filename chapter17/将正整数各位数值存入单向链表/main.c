#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define DEC 10
static void showlist(Item item);
static void get_positive_int(int unsigned *);
static void entry_linklist(int unsigned, List *, Item *);

int main(int argc, char *argv[])
{

	int unsigned n = 0;
	List memlist;
	Item temp;

	printf("Input a positive integers below:\n");
	get_positive_int(&n);
	
	InitializeList(&memlist);
	if (ListIsFull(&memlist))
	{
		fprintf(stderr, "No memory available.\n");
		exit(EXIT_FAILURE);
	}

	entry_linklist(n, &memlist, &temp);

	if (ListIsEmpty(&memlist))
		printf("No data entered.");
	else
		Reverse(&memlist);
		Traverse(&memlist, showlist);
	printf("\n");
	return 0;
}

static void get_positive_int(int unsigned *num)
{
	while (scanf("%u", num) != 1)
	{
		fprintf(stderr, "Input error. Try again.\n");
		while (getchar() != '\n')
			continue;
	}
}

static void showlist(Item item)
{
	printf("%u", item.val);
}

static void entry_linklist(int unsigned num, List *ml, Item *tp)
{
	while (num > 0)
	{
		tp->val  = num % DEC;
		num /= DEC;

		if (AddItem(*tp, ml) == false)
		{
			fprintf(stderr, "Problem allocating memory.\n");
			exit(EXIT_FAILURE);
		}
		if (ListIsFull(ml))
		{
			puts("The list is now full.");
			break;
		}
	}
}
