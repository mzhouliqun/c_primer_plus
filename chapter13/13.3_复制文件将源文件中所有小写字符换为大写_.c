#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FNL 255
int main(void)
{
	FILE *rp, *wp;
	char source[FNL];
	char dest[FNL];
	char ch;

	fprintf(stdout, "Please input the source file:\n");
	while (fscanf(stdin, "%s", source) != 1);
	fprintf(stdout, "Please input the destination file:\n");
	while (fscanf(stdin, "%s", dest) != 1);
	if ((rp = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s.\n", source);
		exit(EXIT_FAILURE);
	}
	if ((wp = fopen(dest, "w")) == NULL)
	{
		fprintf(stderr, "Can not open file %s.\n", dest);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(rp)) != EOF)
	{
		putc(toupper(ch), wp);
	}
	if (fclose(rp) || fclose(wp))
	{
		fprintf(stderr, "Close file failure.\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
