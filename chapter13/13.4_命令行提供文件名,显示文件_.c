#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

	FILE *fp;
	int i = 0;
	char ch;
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s [file1] [file2] ... [filen]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < argc; i++)
	{
		printf("%s:\n",argv[i]);
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can not open file %s.\n", argv[i]);
			continue;
		}
		while ((ch = getc(fp)) != EOF)
			putc(ch, stdout);
		if (fclose(fp))
		{
			fprintf(stderr, "Close file %s failure.\n", argv[i]);
			continue;
		}
		printf("\n");
	}
	return 0;
}
