#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
int has_line(char, char *);
int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	char line[SIZE];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [character] [filename]\n", argv[0]);
		exit(1);
	}
	if (strlen(argv[1]) != 1)
	{
		fprintf(stderr, "The first parameter should be only one character.\n");
		exit(2);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(3);
	}
	while (fgets(line, SIZE, fp) != NULL)
	{
		if (has_line(argv[1][0], line))
			fputs(line, stdout);
	}
	fclose(fp);
	return 0;
}
	
int has_line(char ch, char *line)
{
	while (*line)
		if (ch == *line++)
			return 1;
	return 0;
}
