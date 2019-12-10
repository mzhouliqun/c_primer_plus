#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char ch;
	int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [character]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("Input your article below:\n");
	while ((ch = getc(stdin)) != EOF)
		if (ch == argv[1][0])
			count++;
	printf("You have inputed %d %c\n", count, argv[1][0]);
	return 0;
}
