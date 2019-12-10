#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct pair
{
	Node *parent;
	Node *child;
} Pair;

static Node *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Node *new_node, Node *root);
static void InOrder(const Node *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *pt);
static void DeleteNode(Node **pn);
static void DeleteAllNodes(Node *root);

void InitializeTree(Tree *pt)
{
	pt->root = NULL;
	pt->node_count = 0;
}

bool TreeIsEmpty(const Tree *pt)
{
	return pt->root == NULL;
}

bool TreeIsFull(const Tree *pt)
{
	Node *temp;

	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
		return true;
	else
	{
		free(temp);
		return false;
	}
}

int TreeItemCount(const Tree *pt)
{
	return pt->node_count;
}

bool AddItem(const Item *pi, Tree *pt)
{
	Node *new_node;

	if (TreeIsFull(pt))
	{
		fprintf(stderr, "Tree is full!\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Could not create node!\n");
		return false;
	}
	if (SeekItem(pi, pt).child != NULL)
	{
		SeekItem(pi, pt).child->item.word_count++;
		free(new_node);
		return true;
	}
	if (pt->root == NULL)
		pt->root = new_node;
	else
		AddNode(new_node, pt->root);
	pt->node_count++;
	return true;
}

Node *InItem(const Item *pi, const Tree *pt)
{
	return SeekItem(pi, pt).child;
}

bool DeleteItem(const Item *pi, Tree *pt)
{
	Pair look;

	look = SeekItem(pi, pt);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		DeleteNode(&pt->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	pt->node_count--;
	return true;
}

void Traverse(const Tree *pt, void (*pfun)(Item item))
{
	if (pt != NULL)
		InOrder(pt->root, pfun);
}

void DeleteAll(Tree *pt)
{
	if (pt != NULL)
		DeleteAllNodes(pt->root);
	pt->root = NULL;
	pt->node_count = 0;
}

static Node *MakeNode(const Item *pi)
{
	Node *new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
//	if (strcmp(&i1->word[0], &i2->word[0]) < 0)
	if (strcmp(i1->word, i2->word) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
//	if (strcmp(&i1->word[0], &i2->word[0]) > 0)
	if (strcmp(i1->word, i2->word) > 0)
		return true;
	else
		return false;
}

static void AddNode(Node *new_node, Node *root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "Location error in AddNode()!\n");
		exit(EXIT_FAILURE);
	}
}

static void InOrder(const Node *root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static Pair SeekItem(const Item *pi, const Tree *pt)
{
	Pair look;
	look.parent = NULL;
	look.child = pt->root;

	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

static void DeleteNode(Node **pn)
{
	Node *temp;

	puts((*pn)->item.word);
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

static void DeleteAllNodes(Node *root)
{
	Node *temp;

	if (root != NULL)
	{
		temp = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(temp);
	}
}

