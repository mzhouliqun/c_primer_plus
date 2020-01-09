#include <stdio.h>
#include <stdlib.h>
#include "list.h"
static void showlist(Item item);
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int i = 0;
	FILE *fp;
	List memlist;
	Item temp;

	InitializeList(&memlist);
	if (ListIsFull(&memlist))
	{
		fprintf(stderr, "No memory available! Bye!\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not opent file %s!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(fp, "%d%d", &temp.id, &temp.pid) == 2)
	{
		if (AddItem(temp, &memlist) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&memlist))
		{
			puts("The list is now full.");
			break;
		}
	}
	if (ListIsEmpty(&memlist))
		printf("No data entered.\n");
	else
		Traverse(&memlist, showlist);

	if (fclose(fp))
	{
		fprintf(stderr, "Can not close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}

static void showlist(Item item)
{
	printf("%d %d\n", item.id, item.pid);
}
