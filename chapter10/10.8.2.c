#include <stdio.h>
#define ROWS 3
#define COLS 5
void copy_2d(int m, int n, double (*sou)[COLS], double (*tar)[COLS]);
void display_2d(int m, int n, double (*array)[COLS]);
int main(void)
{
	int r, c;
	double source[ROWS][COLS] = {
	{1.1, 1.2, 1.3, 1.4, 1.5},
	{2.1, 2.2, 2.3, 2.4, 2.5},
	{3.1, 3.2, 3.3, 3.4, 3.5}
	};
	printf("This program is used to demonstrate the process of copying a two-dimensional array.\n");
	printf("Define two-dimensional array:\n");
	printf("source[%d][%d] = {\n", ROWS, COLS);
	printf("{1.1, 1.2, 1.3, 1.4, 1.5},\n");
	printf("{2.1, 2.2, 2.3, 2.4, 2.5},\n");
	printf("{3.1, 3.2, 3.3, 3.4, 3.5}\n");
	printf("};\n");
	double target[][COLS] = {0};
	copy_2d(ROWS, COLS, source, target);
	display_2d(ROWS, COLS, target);
	
/*	for (r = 0; r <  ROWS; r++)
 		for (c = 0; c < COLS; c++)
 			printf("%.1lf ", *(*(target + r) + c));
 	printf("\n");*/
	return 0;
}

void copy_2d(int m, int n, double (*sou)[COLS], double (*tar)[COLS])
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			*(*(tar + i) + j) = *(*(sou + i) + j);
}

void display_2d(int m, int n, double (*target)[COLS])
{
	int r, c, l;
	printf("target[%d][%d] = {\n", m, n);
	for (r = 0; r < m - 1; r++)
	{
		printf("{");
		for (c = 0; c < n - 1; c++)
			printf("%.1lf, ", target[r][c]);
		printf("%.1lf},\n", target[r][n - 1]);
	}
	printf("{");
	for (l = 0; l < n - 1; l++)
		printf("%.1lf, ", target[m - 1][l]);
	printf("%.1lf}\n",target[m - 1][n -1]);
	printf("};\n");
}

