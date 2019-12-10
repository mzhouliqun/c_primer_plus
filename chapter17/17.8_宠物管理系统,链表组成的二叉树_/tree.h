#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>

#define MAX_STR_LEN 20
#define MAX_TREE_SIZE 20

typedef struct item
{
	char petname[20];
	char petkind[20];
} Item;

typedef struct node_list
{
	Item item;
	struct node_list *next;
} List;

typedef struct node_tree
{
	List *list;
	int list_size;
	struct node_tree *left;
	struct node_tree *right;
} Node;

typedef struct tree
{
	Node *root;
	int size;
} Tree;

void InitializeTree(Tree *pt);

bool TreeIsEmpty(const Tree *pt);

bool TreeIsFull(const Tree *pt);

int TreeItemCount(const Tree *pt);

bool InTree(const Item *pi, const Tree *pt);

bool AddTreeItem(const Item *pi, Tree *pt);

bool DeleteItem(const Item *pi, Tree *pt);

void Traverse(const Tree *pt, void (*pfun)(List *pl));

void DeleteAll(Tree *pt);

#endif

