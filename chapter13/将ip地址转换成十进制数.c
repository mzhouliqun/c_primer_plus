#include <stdio.h>
#include <stdlib.h>
long ip_stl(char *);
long pwr(int, int);
int CalLineNum(FILE *);
int main(int argc, char *argv[])
{
	if(argc != 3)
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
	char ip[16];

	for (int i = 0; i < nol; i++)
	{
		fscanf(fps, "%s", ip);
		fprintf(fpd, "%ld\n", ip_stl(ip));
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

long ip_stl(char *str)
{
	int i = 0;
	int j = 0;
	long num[4];
	long sum = 0L;

	for (j = 0; j < 4; j++)
	{
		num[j] = atol(str);
		while (*(str + i) != '.')
			i++;
		str += (i + 1);
		i = 0;
	}
	return(num[0] * 256 * 256 *256 + num[1] * 256 * 256 + num[2] * 256 + num[3]);
}

long pwr(int m, int n)
{
	int i = 0;
	long sum = 1L;

	for (i = 0; i < n; i++)
		sum *= m;
	return sum;
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
