#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
int main(void)
{
	int ch;
	FILE *fp;
	long count = 0;
	char filename[SIZE];

	printf("Please input filename that you want to calculate\n");
	gets(filename);
	if ((fp = fopen (filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", filename);
		exit(1);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	fprintf(stdout,"File %s has %ld characters\n", filename, count);
	return 0;
}
