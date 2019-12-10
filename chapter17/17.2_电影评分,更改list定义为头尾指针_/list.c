#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList (List *plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

bool ListIsEmpty(const List *plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;
}

/*unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = *plist;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}*/

unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = plist->head;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List *plist)
{
	Node *pnew;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (plist->head == NULL)
		plist->head = pnew;
	else
		plist->end->next = pnew;
	plist->end = pnew;
	return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
	Node *pnode = plist->head;


	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List *plist)
{
	Node *psave;
	Node *pnode = plist->head;

	while (pnode != NULL)
	{
		psave = pnode->next;
		free(pnode);
		pnode = psave;
	}
}

static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}

char *s_gets(char *str, int n)
{
	int i = 0;
	char *ret_val;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
