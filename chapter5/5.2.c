#include <stdio.h>
int main(void)
{
	int num;
	int i;

	printf("Please enter an integer:\n");
	while (scanf("%d", &num) < 0)
		getchar();
	for (i = num; i < 10 + num; i++)
		printf("%d ", i);
	printf("%d\n", i);
	return 0;
}
