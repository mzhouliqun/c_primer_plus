#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>

#define MAXLEN 100

typedef struct item
{
	char word[MAXLEN];
	int word_count;
} Item;

typedef struct node
{
	Item item;
	struct node *left;
	struct node *right;
} Node;

typedef struct tree
{
	Node *root;
	int node_count;
} Tree;

void InitializeTree(Tree *pt);

bool TreeIsEmpty(const Tree *pt);

bool TreeIsFull(const Tree *pt);

int TreeItemCount(const Tree *pt);

bool AddItem(const Item *pi, Tree *pt);

Node *InItem(const Item *pi, const Tree *pt);

bool DeleteItem(const Item *pi, Tree *pt);

void Traverse(const Tree *pt, void (*pfun)(Item item));

void DeleteAll(Tree *pt);

#endif
