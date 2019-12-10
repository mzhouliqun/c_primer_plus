#include <stdio.h>
#define ARGU 3
void copy_part(const int *, int *, int);
int main(void)
{
	int i;
	const int count[] = {1, 2, 3, 4, 5, 6, 7};
	int target[] = {0};

	copy_part(count, target, ARGU);
	printf("target[%d] = {", ARGU);
	for (i = 0; i < ARGU - 1; i++)
		printf("%d, ", *(target + i));
	printf("%d}\n", *(target + ARGU - 1));
	return 0;
}

void copy_part(const int *cou, int *tar, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(tar + i) = *(cou + n -1 + i);
}

