#include <stdio.h>
#define STOP '#'
int main(void)
{
	char present;
	char last = '?';
	int count = 0;

	printf("Please input a text, the program will give you the number of times \"ei\" appears, end by '%c'.\n", STOP);
	while ((present = getchar()) != '#')
	{
		if ((last == 'e') && (present == 'i'))
			count++;
		last = present;
	}
	printf("'ei' has appeared %d times in your input.\n", count);
	return 0;
}
