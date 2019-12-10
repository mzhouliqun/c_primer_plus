#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [file_name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char ch;
	FILE *fp;
	int count = 0;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Open file %s failure!\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		if (isspace(ch))
			continue;
		else
		{
			while (!isspace((ch = getc(fp))))
				continue;
			count++;
		}
	}
	printf("The file %s has %d words.\n", argv[1], count);
	if (fclose(fp) != 0)
		fprintf(stdout, "Error in closing file %s.\n", argv[1]);
	return 0;
}
