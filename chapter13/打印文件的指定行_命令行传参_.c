#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENTH_OF_LINE 1024 * 1024
#define MAX_LENTH_OF_FILE 255
int SetPositionByLine(FILE *, int);
void ReadByLine(FILE *, FILE *);
int CalLineNum(FILE *);
int main(int argc, char *argv[])
{
	char buffer[MAX_LENTH_OF_LINE + 1];
	char ch;
	FILE *fp;
	int line;
	int max_line_of_file;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [Filename] [LineNumber]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (!isdigit(argv[2][0]))
	{
		fprintf(stderr, "The line number must be Positive integer\n");
		exit(EXIT_FAILURE);
	}
	max_line_of_file = CalLineNum(fp);
	rewind(fp);
	if (atoi(argv[2]) > max_line_of_file)
		line = max_line_of_file;
	else if (atoi(argv[2]) == 0)
		line = 1;
	else
		line = atoi(argv[2]);
	SetPositionByLine(fp, line);
	ReadByLine(fp, stdout);
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

void ReadByLine(FILE *fp, FILE *op)
{
	char buffer[MAX_LENTH_OF_LINE + 1];

	fgets(buffer, MAX_LENTH_OF_LINE, fp);
	fputs(buffer, op);
}

int CalLineNum(FILE *fp)
{
	char ch;
	int n = 0;

	while ((ch = getc(fp)) != EOF)
		if (ch == '\n')
			n++;
	fseek (fp, -1L, SEEK_END);
	ch = getc(fp);
	if (ch != '\n')
		n++;
	return n;
}
