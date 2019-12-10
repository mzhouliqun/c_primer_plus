#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int i = 0;

	printf("Please input a text end by '%c'\n", STOP);
	while ((ch = getchar()) != STOP)
	{
		printf("%c-->%d\t", ch, ch);
		if ((++i % 8) == 0)
			printf("\n");
	}
	return 0;
}
