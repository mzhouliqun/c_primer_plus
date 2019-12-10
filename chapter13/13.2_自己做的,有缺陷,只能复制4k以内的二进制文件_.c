#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *rp, *wp;
	char ch;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s[filename] [filename]\n", argv[0]);
		exit(1);
	}
	if ((rp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit (2);
	}
	if ((wp = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(3);
	}
	while ((ch = getc(rp)) != EOF)
		putc(ch, wp);
	fclose(rp);
	fclose(wp);
	return 0;
}
