#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//static void CopyToNode(Item item, Node *pnode);

void InitializeList (List *plist)
{
	plist->items = 0;
}

bool ListIsEmpty(const List *plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

bool ListIsFull(const List *plist)
{
	if (plist->items < MAXSIZE)
		return false;
	else
		return true;
}

unsigned int ListItemCount(const List *plist)
{
	return plist->items;
}

bool AddItem(Item item, List *plist)
{
	int i = plist->items;

	if (i < MAXSIZE)
	{
		plist->entries[i] = item;
		plist->items++;
		return true;
	}
	else
		return false;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
	if (plist->items == 0)
		return;
	else
		for (int i = 0; i < plist->items; i++)
			(*pfun)(plist->entries[i]);
}

void EmptyTheList(List *plist)
{
	plist->items = 0;
}

//static void CopyToNode(Item item, Node *pnode)
//{
//	pnode->item = item;
//}

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
