#pragma c9x on
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef struct queue
{
	Node *front;
	Node *rear;
	int items;
} Queue;

void InitializeQueue(Queue *pq);
bool QueueIsFull(const Queue *pd);
bool QueueIsEmpty(const Queue *pd);
int QueueItemCount(const Queue *pd);
bool EnQueue(Item item, Queue *pd);
bool DeQueue(Item *pitem, Queue *pd);
void EmptyTheQueue(Queue *pd);

#endif
