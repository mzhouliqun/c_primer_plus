#include <stdio.h>
#include <string.h>
#define SIZE 1001
void left(char *);
int main(void)
{
		char string[SIZE];

		gets(string);
		left(string);
		puts(string);

		return 0;
}

void left(char * str)
{
		for (; *(str + 1) != '\0';str++)
				*str = *(str + 1);
		*str = '\0';
}
