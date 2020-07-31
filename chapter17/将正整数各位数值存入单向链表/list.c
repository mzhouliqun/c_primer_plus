#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);
static Node *ReverseNode(Node *head);

void InitializeList(List *plist)
{
	*plist = NULL;
}

bool ListIsEmpty(const List *plist)
{
	if (*plist == NULL)
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

unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = *plist;

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
	Node *scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
	Node *pnode = *plist;
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List *plist)
{
	Node *psave;
	free(*plist);
	*plist = psave;
}

static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}

static Node *ReverseNode(Node *head)
{
	Node  *reverse_head;
	Node  *n;
	Node  *p = NULL;
	Node  *c = head;
	while (c != NULL)
	{
		n = c->next;
		if (n == NULL)
		reverse_head = c;
		c->next = p;
		p = c;
		c = n;
	}
	return reverse_head;
}

void Reverse(List *plist)
{
	Node *pnode = *plist;
	*plist = ReverseNode(pnode);
}
