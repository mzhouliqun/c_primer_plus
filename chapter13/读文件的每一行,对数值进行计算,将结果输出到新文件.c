#include <stdio.h>
#include <stdlib.h>
int CalLineNum(FILE *);
long cal(long);
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [source file_name] [destination file_name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *fps = NULL;
	FILE *fpd = NULL;

	if ((fps = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Read source file %s failure!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fpd = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Read destination file %s failure!\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	int nol = CalLineNum(fps);
	char str[nol];

	for (int i = 0; i < nol; i++)
	{
		fscanf(fps, "%s", str);
		fprintf(fpd, "%ld\n", cal(atol (str)));
	}

	if (fclose(fps))
	{
		fprintf(stderr, "Can not close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fclose(fpd))
	{
		fprintf(stderr, "Can not close file %s\n", argv[2]);
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
	fseek(fp, 0L, SEEK_SET);
	return n;
}

long cal(long n)
{
	return(n /= 2);
}
