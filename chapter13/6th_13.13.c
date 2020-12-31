/* data example:
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define ROWS 20
#define COLS 30
char itoc(int);
void display_char(int, int, char(*)[]);
int judge_edge_value(int, int []);
void process(int rows, int cols, int dgt[rows][cols]);
int main(int argc, char *argv[])
{
	int i;
	int j;
	int num;
	int rows = ROWS;
	int cols = COLS;
	int digit[rows][cols];
	char image[rows][cols + 1];
	char ch;
	FILE *fp1, *fp2, *fp3;

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s [digit_character_file] [output_source-image_file] [output_processed-image_file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if ((fp3 = fopen(argv[3], "w")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[3]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp1)) != EOF)
		if (!isdigit(ch) && !isspace(ch))
		{
			fprintf(stderr, "file %s exists not blank and non numeric characters\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	rewind(fp1);
 	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			fscanf(fp1, "%d", &num);
			digit[i][j] = num;
			image[i][j] = itoc(num);
		}
		image[i][cols] = '\0';
		fprintf(fp2, "%s\n", image[i]);
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			fprintf(stdout, "%d", digit[i][j]);
		fprintf(stdout, "\n");
	}
	display_char(rows, cols, image);
	printf("\n\n-----Image peak processing------\n\n");
	process(rows, cols, digit);
	memset(image, 0, sizeof(image));
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			image[i][j] = itoc(digit[i][j]);
		fprintf(fp3, "%s\n", image[i]);
	}
	display_char(rows, cols, image);
	if (fclose(fp1))
	{
		fprintf(stderr, "Can not close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fclose(fp2))
	{
		fprintf(stderr, "Can not close file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if (fclose(fp3))
	{
		fprintf(stderr, "Can not close file %s\n", argv[3]);
		exit(EXIT_FAILURE);
	}
	return 0;
}

char itoc(int n)
{
	char ch[] = " .':~*=7%#";
	return ch[n];
}

void display_char (int n, int m, char(*string)[m + 1])
{
	int i;
	for (i = 0; i < n; i++)
	{
		fputs(*(string + i), stdout);
		fprintf(stdout, "\n");
	}
}

int judge_edge_value(int n, int jm[n])
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (jm[i] > 1)
			continue;
		else
			return 0;
	}
	return 1;
}

void process(int rows, int cols, int dgt[rows][cols])
{
	int i = 0;
	int j = 0;
	int temp[4] = {0};

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					temp[0] = abs(dgt[i][j] - dgt[i][j + 1]);
					temp[1] = abs(dgt[i][j] - dgt[i + 1][j]);
					if (judge_edge_value(2, temp))
						dgt[i][j] = (dgt[i][j + 1] + dgt[i + 1][j]) / 2;
				}
				else if (j == (cols - 1))
				{
					temp[0] = abs(dgt[i][j] - dgt[i][j - 1]);
					temp[1] = abs(dgt[i][j] - dgt[i + 1][j]);
					if (judge_edge_value(2, temp))
						dgt[i][j] = (dgt[i][j - 1] + dgt[i + 1][j]) / 2;
				}
				else
				{
					temp[0] = abs(dgt[i][j] - dgt[i][j - 1]);
					temp[1] = abs(dgt[i][j] - dgt[i + 1][j]);
					temp[2] = abs(dgt[i][j] - dgt[i][j + 1]);
					if (judge_edge_value(3, temp))
						dgt[i][j] = (dgt[i][j - 1] + dgt[i][j + 1] + dgt[i + 1][j]) / 3;
				}
			}
			else if (i == (rows - 1))
			{
				if (j == 0)
				{
					temp[0] = abs(dgt[i][j] - dgt[i - 1][j]);
					temp[1] = abs(dgt[i][j] - dgt[i][j + 1]);
					if (judge_edge_value(2, temp))
						dgt[i][j] = (dgt[i - 1][j] + dgt[i][j + 1]) / 2;
				}
				else if (j == (cols - 1))
				{
					temp[0] = abs(dgt[i][j] - dgt[i][j - 1]);
					temp[1] = abs(dgt[i][j] - dgt[i - 1][j]);
					if (judge_edge_value(2, temp))
						dgt[i][j] = (dgt[i - 1][j] + dgt[i][j + 1]) / 2;
				}
				else
				{
					temp[0] = abs (dgt[i][j] - dgt[i][j - 1]);
					temp[1] = abs (dgt[i][j] - dgt[i - 1][j]);
					temp[2] = abs (dgt[i][j] - dgt[i][j + 1]);
					if (judge_edge_value(3, temp))
						dgt[i][j] = (dgt[i][j - 1] + dgt[i - 1][j] + dgt[i][j + 1]) / 3;
				}
			}
			else
			{
				if (j == 0)
				{
					temp[0] = abs(dgt[i][j] - dgt[i - 1][j]);
					temp[1] = abs(dgt[i][j] - dgt[i][j + 1]);
					temp[2] = abs(dgt[i][j] - dgt[i + 1][j]);
					if (judge_edge_value(3, temp))
						dgt[i][j] = (dgt[i - 1][j] + dgt[i][j + 1] + dgt[i + 1][j]) / 3;
				}
				else if (j == (cols - 1))
				{
					temp[0] = abs(dgt[i][j] - dgt[i - 1][j]);
					temp[1] = abs(dgt[i][j] - dgt[i][j - 1]);
					temp[2] = abs(dgt[i][j] - dgt[i + 1][j]);
					if (judge_edge_value(3, temp))
						dgt[i][j] = (dgt[i - 1][j] + dgt[i][j - 1] + dgt[i + 1][j]) / 3;
				}
				else
				{
					temp[0] = abs(dgt[i][j] - dgt[i][j - 1]);
					temp[1] = abs(dgt[i][j] - dgt[i - 1][j]);
					temp[2] = abs(dgt[i][j] - dgt[i][j + 1]);
					temp[3] = abs(dgt[i][j] - dgt[i + 1][j]);
					if (judge_edge_value(4, temp))
						dgt[i][j] = (dgt[i][j - 1] + dgt[i - 1][j] + dgt[i][j + 1] + dgt[i + 1][j]) / 4;
				}
			}
		}
}
