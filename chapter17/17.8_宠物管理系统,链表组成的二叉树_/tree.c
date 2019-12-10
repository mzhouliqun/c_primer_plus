#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct pair
{
	Node *parent;
	Node *child;
} Pair;

static bool AddListItem(const Item *pi, Node *root);
static List *MakeListNode(const Item *pi);
static Node *MakeTreeNode(const Item *pi);
static void AddTreeNode(Node *new_node, Node *root);
static Pair SeekTreeItem(const Item *pi, const Tree *pt);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static bool SeekListItem(const Item *pi, List *pl);
static void DeleteTreeNode(const Item *pi, Node **pn);
static List *DeleteListNode(const Item *pi, List *pl);
static void InOrder(const Node *root, void (*pfun)(List *pl));
static void DeleteAllNodes(Node *root);
static void DeleteList(List *pl);

static bool AddListItem(const Item *pi, Node *root)
{
	List *new_listnode;
	List *temp = root->list;

	new_listnode = MakeListNode(pi);
	if (new_listnode == NULL)
	{
		fprintf(stderr, "Adding a new member failed!\n");
		return false;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_listnode;
	root->list_size++;
	return true;
}

static List *MakeListNode(const Item *pi)
{
	List *new_list;

	new_list = (List *)malloc(sizeof(List));
	if (new_list != NULL)
	{
		new_list->item = *pi;
		new_list->next = NULL;
	}
	return new_list;
}

static Node *MakeTreeNode(const Item *pi)
{
	Node *new_node;
	List *new_list_node;

	new_list_node = MakeListNode(pi);
	if (new_list_node == NULL)
		return NULL;
	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->list = new_list_node;
		new_node->list_size = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static void AddTreeNode(Node *new_node, Node *root)
{
	if (ToLeft(&new_node->list->item, &root->list->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddTreeNode(new_node, root->left);
	}
	else if (ToRight(&new_node->list->item, &root->list->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddTreeNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "Location error in AddTreeNode()!\n");
		exit(EXIT_FAILURE);
	}
}

static bool ToLeft(const Item *i1, const Item *i2)
{
	if (strcmp(i1->petname, i2->petname) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
	if (strcmp(i1->petname, i2->petname) > 0)
		return true;
	else
		return false;
}

static bool SeekListItem(const Item *pi, List *pl)
{
	List *temp = pl;

	while (NULL != temp)
	{
		if (strcmp(pi->petkind, temp->item.petkind) == 0)
			return true;
		temp = temp->next;
	}
	return false;
}

static Pair SeekTreeItem(const Item *pi, const Tree *pt)
{
	Pair look;
	look.parent = NULL;
	look.child = pt->root;

	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &look.child->list->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &look.child->list->item))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

static void DeleteTreeNode(const Item *pi, Node **pn)
{
	Node *temp;

	if ((*pn)->list_size == 1)
	{
		if ((*pn)->left == NULL)
		{
			temp = *pn;
			*pn = (*pn)->right;
			free(temp);
		}
		else if ((*pn)->right == NULL)
		{
			temp = *pn;
			*pn = (*pn)->left;
			free(temp);
		}
		else
		{
			temp = (*pn)->left;
			while (temp->right != NULL)
				temp = temp->right;
			temp->right = (*pn)->right;
			temp = *pn;
			*pn = (*pn)->left;
			free(temp);
		}
	}
	else if ((*pn)->list_size > 1)
	{
		(*pn)->list = DeleteListNode(pi, (*pn)->list);
		(*pn)->list_size--;
	}
}

static List *DeleteListNode(const Item *pi, List *pl)
{
	List *phead = pl;
	List *temp;

	if (strcmp(pi->petkind, phead->item.petkind) == 0)
	{
		phead = pl->next;
		free(pl);
	}
	else
	{
		while (strcmp(pi->petkind, pl->item.petkind) != 0)
		{
			temp = pl;
			pl = pl->next;
		}
		temp->next = pl->next;
		free(pl);
	}
	return phead;
}

static void InOrder(const Node *root, void (*pfun)(List *pl))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->list);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Node *root)
{
	Node *temp = root;

	if (root != NULL)
	{
		temp = root->right;
		DeleteAllNodes(root->left);
		DeleteList(root->list);
		free(root);
		DeleteAllNodes(temp);
	}
}

static void DeleteList(List *pl)
{
	List *temp;

	while (pl != NULL)
	{
		temp = pl;
		pl = pl->next;
		free(temp);
	}
}

void InitializeTree(Tree *pt)
{
	pt->root = NULL;
	pt->size = 0;
}

bool TreeIsEmpty(const Tree *pt)
{
	return pt->root == NULL;
}

bool TreeIsFull(const Tree *pt)
{
	return pt->size >= MAX_TREE_SIZE;
}

int TreeItemCount(const Tree *pt)
{
	return pt->size;
}

bool InTree(const Item *pi, const Tree *pt)
{
	Pair look = SeekTreeItem(pi, pt);
	return look.child != NULL && SeekListItem(pi, look.child->list);
}

bool AddTreeItem(const Item *pi, Tree *pt)
{
	Node *new_node;
	Pair look;

	if (TreeIsFull(pt))
	{
		fprintf(stderr, "Tree is Full!\n");
		return false;
	}
	look = SeekTreeItem(pi, pt);
	if (look.child != NULL)
	{
		if (AddListItem(pi, look.child))
			return true;
		else
		{
			fprintf(stderr, "Location error in AddTreeItem()!\n");
			return false;
		}
	}
	new_node = MakeTreeNode(pi);
	if (new_node  == NULL)
	{
		fprintf(stderr, "Could not create node\n");
		return false;
	}
	if (pt->root == NULL)
		pt->root = new_node;
	else
		AddTreeNode(new_node, pt->root);
	pt->size++;
	return true;
}

bool DeleteItem(const Item *pi, Tree *pt)
{
	Pair look;
	look = SeekTreeItem(pi, pt);

	if (look.child == NULL)
		return false;
	if (!SeekListItem(pi, look.child->list))
		return false;
	if (look.parent == NULL)
		DeleteTreeNode(pi, &pt->root);
	else if (look.parent->left == look.child)
		DeleteTreeNode(pi, &look.parent->left);
	else
		DeleteTreeNode(pi, &look.parent->right);
	pt->size--;
	return true;
}

void Traverse(const Tree *pt, void (*pfun)(List *pl))
{
	if (pt->root != NULL)
		InOrder(pt->root, pfun);
}

void DeleteAll(Tree *pt)
{
	if (pt->root != NULL)
		DeleteAllNodes(pt->root);
	pt->size = 0;
}



