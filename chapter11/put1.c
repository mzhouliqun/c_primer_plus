#include <stdio.h>
#define SIZE 1000
void put1(const char *);
int main(void)
{
	char msg[SIZE];
	printf("This program used to test function put1\n");
	puts("Input something!");

	gets(msg);
	put1(msg);
	return 0;
}

void put1(const char *string)
{
	while (*string)
		putchar(*string++);
}
