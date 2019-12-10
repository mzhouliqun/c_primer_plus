#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIV 10
#define COUNT 100
void rank(int *, int);
int main(void)
{
	int i;
	int num[COUNT] = {0};
	srand((unsigned int) time (0));
	for (i = 0; i < COUNT; i++)
		num[i] = rand() % DIV + 1;
	rank(num, COUNT);
	for (i = 0; i < COUNT; i++)
		printf("%d ", num[i]);
	printf("\n");
	return 0;
}

void rank(int *str, int n)
{
	int *temp;
	int top, seek;

	for (top = 0; top < COUNT - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (*(str + top) < *(str + seek))
			{
				*temp = str[top];
				str[top] = str[seek];
				str[seek] = *temp;
			}
}
