#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeStack(Stack *ps)
{
	ps->top = NULL;
	ps->bottom = NULL;
}

bool StackIsFull(const Stack *ps)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
		return true;
	else
		return false;
	free(temp);
}

bool StackIsEmpty(const Stack *ps)
{
	return ps->top == NULL;
}

bool Push(Item item, Stack *ps)
{
	Node *pnew;

	if (StackIsFull(ps))
		return false;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	CopyToNode(item, pnew);
	if (StackIsEmpty(ps))
	{
		pnew->next = NULL;
		ps->bottom = pnew;
	}
	else
		pnew->next = ps->top;
	ps->top = pnew;
	return true;
}

bool Pop(Item *pitem, Stack *ps)
{
	Node *pt;

	if (StackIsEmpty(ps))
		return false;
	CopyToItem(ps->top, pitem);
	pt = ps->top;
	ps->top = ps->top->next;
	free(pt);
	if (ps->top == NULL)
		ps->bottom = NULL;
	return true;
}

static void CopyToNode(Item item, Node *pn)
{
	pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
	*pi = pn->item;
}
