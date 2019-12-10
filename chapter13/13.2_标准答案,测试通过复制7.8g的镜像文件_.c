#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024 * 1024
int main(int argc, char *argv[])
{
	FILE *rp, *wp;
	char ch;
	char buf[BUFSIZE];
	int count = 0;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s[filename] [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((rp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((wp = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((count = fread(buf, sizeof (char), BUFSIZE, rp)) != 0)
		fwrite(buf, sizeof(char), count, wp);
	if (ferror(rp) || ferror(wp))
	{
		fprintf(stderr, "copy failure\n");
		exit(EXIT_FAILURE);
	}
	if (fclose(rp) || fclose(wp))
	{
		fprintf(stderr, "can not close file\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
