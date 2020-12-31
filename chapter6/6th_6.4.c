#include <stdio.h>
int main(void)
{
	char ch = 'A';
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < 6; i++)
	{
		for (j = k; j <= k + i; j++)
			printf("%c", ch + j + i);
		k = j - 1;
		printf("\n");
	}
	return 0;
}
