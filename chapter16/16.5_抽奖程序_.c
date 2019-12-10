#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define RANGE 100

static unsigned int next = 1;

int mytime(void);
void srand1(unsigned int);
int rand1(int);
void create_array(int *, int);
void extract(int *, int, int);

int main(void)
{
	int num;
	int *p;
	int sz[RANGE] = {0};
	p = sz;

	printf("Please input the number of extraction: ");
	while (scanf("%d", &num) != 1 || num <= 0 || num > RANGE)
	{
		getchar();
		printf("Input error. Try again!\n");
	}
	create_array(p, RANGE);
	extract(p, RANGE, num);
	return 0;
}

int mytime(void)
{
	int seconds = time((time_t *)NULL);
	return seconds;
}

int rand1(int n)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65535) % n;
}

void srand1(unsigned int seed)
{
	next = seed;
}

void create_array(int *p, int n)
{
	if (n <= 0)
		exit(EXIT_FAILURE);
	
	for (int i = 0; i < n; i++)
		*(p + i) = i + 1;
}

void extract(int *array, int range, int n)
{
	int sz[RANGE] = {0};
	int temp;
	unsigned seed;

	for (int i = 0; i < n; i++)
	{
		seed = (unsigned int)mytime();
		srand1(seed);
		temp = rand1(range - i);
		sz[i] = array[temp];
		for (int j = temp; j < range; j++)
			array[j] = array[j + 1];
		sleep(1);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", sz[i]);
}
