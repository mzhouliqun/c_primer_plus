#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define DEC 10
static void showlist(Item);
static List *addTwoNumbers(List *, List *);
static List *fibonacci(int);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [Positive integer]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int num = atoi(argv[1]);

	Item temp = {.val = 0};

	List *lc = fibonacci(num);
	Reverse(lc);
	Traverse(lc, showlist);
	printf("\n");
	EmptyTheList(lc);
	free(lc);
	return 0;
}

static void showlist(Item item)
{
	printf("%u", item.val);
}

static List *addTwoNumbers(List *l1, List *l2)
{
	int carry_num = 0;
	Node *pnode1 = *l1;
	Node *pnode2 = *l2;
	Item temp;

	List *slp = (List *)malloc(sizeof(List));
	

	while (pnode1 != NULL || pnode2 != NULL || carry_num)
	{	

		int sum = 0;
		int last_carry = carry_num;
		if (pnode1 != NULL)
		{
			sum += (pnode1->item).val;
			pnode1 = pnode1->next;
		}
		if (pnode2 != NULL)
		{
			sum += (pnode2->item).val;
			pnode2 = pnode2->next;
		}
		if (sum >= 10)
		{
			sum -= 10;
			carry_num = 1;
		}
		else
		{
			carry_num = 0;
		}

		temp.val = sum + last_carry;
		if (temp.val >= 10)
		{
			temp.val -= 10;
			carry_num = 1;
		}
		if (AddItem(temp, slp) == false)
		{
			fprintf(stderr, "Problem allocating memory.\n");
			exit(EXIT_FAILURE);
		}
	}
	return slp;
}

List *fibonacci(int n)
{
	int index = 0;
	List *la = (List *)malloc(sizeof(List));
	List *lb = (List *)malloc(sizeof(List));
	List *lc;
	Item temp = {.val = 1};


	if (AddItem(temp, la) == false)
	{
		fprintf(stderr, "Problem allocating memory.\n");
		exit(EXIT_FAILURE);
	}
	if (AddItem(temp, lb) == false)
	{
		fprintf(stderr, "Problem allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	if (n <= 0)
	{
		fprintf(stderr, "The item number must be positive integer.\n");
		exit(EXIT_FAILURE);
	}
	else if (n < 3)
		lc = la;
	else
	{
		n -= 2;
		while (index < n)
		{
			lc = addTwoNumbers(la, lb);
//			EmptyTheList(la);
			la = lb;
			lb = lc;
			index++;
		}
	}
	return lc;
}
