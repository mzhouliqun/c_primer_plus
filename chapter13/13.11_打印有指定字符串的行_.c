#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH_OF_LINE 1024 * 1024
int CalLineNum(FILE *);
int main(int argc, char *argv[])
{
	FILE *fp;
	int maxline;
	int i;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [string] [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	maxline = CalLineNum(fp);
	rewind(fp);
	for (i = 1; i <= maxline; i++)
	{
		char temp[MAX_LENGTH_OF_LINE + 1];

		fgets(temp, MAX_LENGTH_OF_LINE, fp);
		if ((strstr(temp, argv[1])) != NULL)
		{
			fputs(temp, stdout);
			memset(temp, 0, sizeof(temp));
		}
	}
	if (fclose(fp))
	{
		fprintf(stderr, "Can not close file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return 0;
}

int CalLineNum(FILE *fp)
{
	char ch;
	int n = 0;

	while ((ch = getc(fp)) != EOF)
		if (ch == '\n')
			n++;
	fseek(fp, -1L, SEEK_END);
	ch = getc(fp);
	if (ch != '\n')
		n++;
	return n;
}
