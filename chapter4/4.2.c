#include <stdio.h>
#include <string.h>
#define LEN 100
int main(void)
{
	char name[LEN];
	int width;

	printf("What is your name?\n");
	scanf("%s", name);
	width = strlen(name) + 3;

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n", width, name);
	return 0;
}
