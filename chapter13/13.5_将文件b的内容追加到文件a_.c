#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
void append(FILE *source, FILE *dest);
int main(int argc, char *argv[])
{
	FILE *fa, *fs;

	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s [target_file] [appendix_file]\n", argv[0]);
		exit(1);
	}
	if ((fa = fopen(argv[1], "a")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(2);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't append file to itself\n", stderr);
		exit(3);
	}
	if (strcmp(argv[2], argv[1]) == 0)
		fputs("Can't append file to itself\n", stderr);
	else if ((fs = fopen(argv[2], "r")) == NULL)
		fprintf(stderr, "Can't open %s\n", argv[2]);
	else
	{
		if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fputs("Can't create input buffer\n", stderr);
			exit(4);
		}
		append(fs, fa);
		if (ferror(fs) != 0)
			fprintf(stderr, "Error in reading file %s.\n", argv[2]);
		if (ferror(fa) != 0)
			fprintf(stderr, "Error in writing file %s.\n",argv[1]);
		if (fclose(fs))
		{
			fprintf(stderr, "Can't close file %s.\n", argv[2]);
			exit(5);
		}
	}
	if (fclose(fa))
	{
		fprintf(stderr, "Can't close file %s.\n", argv[1]);
		exit(6);
	}
	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}
