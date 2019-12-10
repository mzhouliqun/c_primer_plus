#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
int main(int argc, char *argv[])
{
	int n = 0;
	char ch;
	FILE *fp;
	char words[SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stdout, "Can't open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		if (isspace(ch))
			n++;
	}
	puts("Enter words to add to the files: press the [Cltr] + [D]");
	puts("at the begining of a line to terminate.");
	while (fscanf(stdin, "%s", words) == 1)
	{
		n++;
		fprintf(fp, "%d:%s ", n, words);
		memset(words, 0, sizeof (words));
		fflush(fp);
	}
	puts("File contents:");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	if (fclose(fp))
		fprintf(stderr, "Error closing file \"%s\"\n", argv[1]);
	return 0;
}
