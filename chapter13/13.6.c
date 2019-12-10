#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(void)
{
	FILE *in, *out;
	int ch;
	char source[LEN];
	char copy[LEN];
	int count = 0;

	fprintf(stdout, "Please input the name of source file:\n");
	while ((fscanf(stdin, "%s", source)) != 1);
	if ((in = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", source);
		exit(2);
	}
	strcpy(copy, source);
	strcat(copy, ".red");
	if ((out = fopen(copy, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
	return 0;
}
