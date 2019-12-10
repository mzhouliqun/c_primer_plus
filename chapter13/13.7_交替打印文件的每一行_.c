#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024 * 1024
#define FNLEN 255
void del_li(char *);
int main(int argc, char *argv[])
{
	FILE *fp01, *fp02;
	char name01[FNLEN] = {0};
	char name02[FNLEN] = {0};
	char row[BUFSIZE] = {0};
	char mode = 'a';

	if (argc == 1)
	{
		fprintf(stdout, "Please enter the first file name:\n");
		fscanf(stdin, "%s", name01);
		fprintf(stdout, "Please enter the second file name:\n");
		fscanf(stdin, "%s", name02);
	}
	else if (argc == 2)
	{
		strcpy(name01, argv[1]);
		fprintf(stdout, "Please enter the second file name:\n");
                fscanf(stdin, "%s", name02);
	}
	else if (argc == 3)
	{
		strcpy(name01, argv[1]);
		strcpy(name02, argv[2]);
	}
	else if (argc == 4)
	{
		strcpy(name01, argv[1]);
                strcpy(name02, argv[2]);
		if (argv[3][0] == 'b')
			mode = 'b';
	}
	else
	{
		fprintf(stderr, "Usage: %s [filename01] [filename02] (mode)  'a|b', default mode is a.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp01 = fopen(name01, "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", name01);
		exit(EXIT_FAILURE);
	}
	if ((fp02 = fopen(name02, "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", name02);
		exit(EXIT_FAILURE);
	}
	while (!feof(fp01) || !feof(fp02))	//As long as there is one file without end, loop will continue.
	{
		if (!feof(fp01))
		{
			memset (row, 0, sizeof(row));
			fgets(row, sizeof(row), fp01);
			if (mode == 'b')
				del_li(row);
			fprintf(stdout, "%s", row);
		}
		if (!feof(fp02))
		{
			memset(row, 0, sizeof(row));
			fgets(row, sizeof(row), fp02);
			if (mode == 'b')
				del_li(row);
			fprintf(stdout, "%s", row);
		}
		if (mode == 'b')
			fprintf(stdout, "\n");
	}
	if (fclose(fp01) || fclose(fp02))
	{
		fprintf(stdout, "Close file failure\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}

void del_li(char *s)
{
	char *i;
	if ((i = strchr(s, '\n')) != NULL)
		*i = '\0';
}
