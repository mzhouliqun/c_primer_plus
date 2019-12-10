#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENTH_OF_LINE 1024 * 1024
#define MAX_LENTH_OF_FILE 255
#define MAX_LENTH_FO_NUM 20
int SetPositionByLine(FILE *, int);
void ReadByLine(FILE *, FILE *, int);
int CalLineNum(FILE *);
int row;
int col;
int main(int argc, char *argv[])
{
	char buffer[MAX_LENTH_OF_LINE + 1];
	char filename[MAX_LENTH_OF_FILE + 1];
	char temp[MAX_LENTH_FO_NUM + 1];
	char ch;
	FILE *fp;
	int max_line_of_file;
	
	printf("Please input the file name:\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	max_line_of_file = CalLineNum(fp);
	rewind(fp);
	printf("Please input position of file %s(q to quit):\n", filename);
	while (scanf ("%d %d", &row, &col) == 2)
	{
		if (row == 0)
			fprintf(stderr, "Out of range! Line number must greater than 0\n");
		else if (row > max_line_of_file)
			fprintf(stderr, "Out of range! file %s only has %d line(s)\n", filename, max_line_of_file);
		else
		{
			SetPositionByLine(fp, row);
			ReadByLine(fp, stdout, col);
			printf("\n");
			printf("Please input position of file %s(q to quit):\n", filename);
		}
	}
	if (fclose(fp))
	{
		fprintf(stdout, "Can not close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}

int SetPositionByLine(FILE *fp, int nLine)
{
	int i;
	char buffer[MAX_LENTH_OF_LINE + 1];
	fpos_t pos;

	rewind(fp);
	for (i = 1; i < nLine; i++)
		fgets(buffer, MAX_LENTH_OF_LINE, fp);
	fgetpos(fp, &pos);
	return 0;
}

void ReadByLine(FILE *fp, FILE *op, int n)
{
	char buffer[MAX_LENTH_OF_LINE + 1];
	char ch;
	int i;
	int len;

	fgets(buffer, MAX_LENTH_OF_LINE, fp);
	for (i = 0; *(buffer + i) != '\n' && *(buffer + i) != '\0'; i++);
	len = i;
	if (n > len)
		fprintf(stderr, "Out of the range! Row %d only has %d character(s)\n", row, len);
	else
	{
		i = 0;
		while (*(buffer + n + i - 1) != '\n' && *(buffer + n + i -1) != '\0')
		{
			putchar(*(buffer + n + i - 1));
			i++;
		}
	}
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
	return n;
}
