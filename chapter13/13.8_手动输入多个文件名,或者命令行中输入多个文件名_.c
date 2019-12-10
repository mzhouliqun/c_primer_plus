#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TNOF 100
#define TLOF 255
int count_char(FILE *, char ch);
int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	int count = 0;
	int i = 0;

	char filename[TNOF][TLOF] = {0};

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s [charcter] (file_1 ... file_n)\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		printf("Please input file names(double [Enter] to quit)\n");
		printf("\nfile%d:\n\n", i + 1);
		while (gets(filename[i]) != NULL && filename[i][0] != '\0')
		{
			i++;
			printf("\nfile%d:\n\n", i + 1);
		}
		count = i;
	}
	else if (argc > (TNOF + 2))
	{
		fprintf(stderr, "%s: Argument list too long\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (i = 0; i < argc - 2; i++)
			strcpy(filename[i], argv[i + 2]);
		count = argc - 2;
	}
	for (i = 0; i < count; i++)
	{
		if ((fp = fopen(filename[i], "r")) == NULL)
		{
			fprintf(stderr, "Can not open file %s\n", filename[i]);
			continue;
		}
		printf("There is %d %c in %s\n", count_char (fp, argv[1][0]), argv[1][0], filename[i]);
		if (fclose (fp))
		{
			fprintf(stderr, "Can not close file %s\n", filename[i]);
			continue;
		}
	}
	return 0;
}

int count_char(FILE *rp, char t)
{
	char ch;
	int num = 0;

	while ((ch = getc(rp)) != EOF)
	{
		if (ch == t)		
			num++;
	}
	return(num);
}
