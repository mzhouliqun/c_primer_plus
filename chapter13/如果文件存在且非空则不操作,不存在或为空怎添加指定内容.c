#include <stdio.h>
#include <stdlib.h>
#define LEN 21
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fp;
	char ch;
	char head[LEN] = "#!/usr/bin/python3";

	if ((fp = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ch = getc(fp);
	fseek(fp, 0L, SEEK_SET);
	if (ch == EOF)
		fprintf(fp, "%s", head);
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error in close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
