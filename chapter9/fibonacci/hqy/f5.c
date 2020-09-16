#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const unsigned long RADIX = 1L<<60;

typedef struct node
{
	unsigned long value;
	struct node  *next;
} Node, *Pnode;

Pnode newNode(unsigned long value)
{
	Pnode p;
	p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	p->value = value;
	return p;
}

Pnode add(Pnode a, Pnode b)
{
	Pnode p0, p1;
	unsigned long v = 0;
	p0 = a;
	p1 = b;

	while (p1 != NULL)
	{
		v = p1->value + p0->value + v;
		p0->value = v %  RADIX;//每节点放入最多RADIX
		v = v / RADIX;
		p1 = p1->next;
		if (p1 != NULL)
		{
			if (p0->next == NULL)
				p0->next = newNode(0);
			p0 = p0->next;
		}
	}
	while (v > 0)
	{
		if (p0->next == NULL)
			p0->next = newNode(0);
		p0 = p0->next;
		v = p0->value + v;
		p0->value = v % RADIX;//每节点放入最多RADIX
		v = v / RADIX;
	}
	return a;
}
void freeList(Pnode node)
{
	Pnode p;
	p = node;
	while (p != NULL)
	{
		p = node->next;
		free(node);
		node = p;
	}
}

Pnode reverse(Pnode p)
{
	Pnode p0 = p, p1 = p0->next, tmp;// t = p->next;
	while (p1 != NULL)
	{
		tmp = p1->next;
		p1->next = p0;
		p0 = p1;
		p1 = tmp;
	}
	p->next = NULL;
	return p0;
}

char *toString(Pnode p)
{
	char *dec;
	int size = 512;
	dec = (char *)malloc(size);//
	int len = 0;
	Pnode head = reverse(p);
	p = head;
	int i;
	unsigned long carry;
	unsigned long v;
	while (p != NULL)
	{
		carry = p->value;
		for (i = 0; i < len; i++)
		{
			v = dec[i] * RADIX + carry;
			dec[i] = (char)(v % 10);
			carry = v / 10;
		}
		while (carry > 0)
		{
			if (len >= size)
			{
				size = size + 512;//每次扩容512
				dec = (char *)realloc(dec, size);
			}
			dec[len] = (char)(carry % 10);
			len++;
			carry = carry / 10;
		}
		p = p->next;
	}
	char *s = (char *)malloc(len + 1);
	int j;
	for (i = len - 1, j = 0; i >= 0; i--, j++)
	   s[j] = (char)(dec[i] + 48);
	s[len] = 0;
	free(dec);
	return s;
}

void fib(unsigned long n, char **s)
{
	clock_t start, finish;
	double  duration;
	start = clock();
	Pnode a, b, c;
	a = newNode(1);
	b = newNode(1);
	for (unsigned long i = 2; i < n; i++)
	{
		c = b;
		b = add(a, b);
		a = c;
	}
	freeList(a);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);

	*s = toString(b);
	freeList(b);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [Postive integer]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	unsigned long num;
	if (*argv[1] == '-' || (num = strtol(argv[1], NULL, 10)) == 0)
	{
		fprintf(stderr, "The number of items in a sequence must be positive integers.\n");
		exit(EXIT_FAILURE);
	}
	int count = 0;
	char *s = NULL;
	fib(num, &s);
	count = strlen(s);
	printf("len:%d \n", count);
	for (int i = 0; i < count; i++)
		printf("%c", *(s + i));
	printf("\n");
	if (s != NULL)
	free(s);
	return 0;
}
