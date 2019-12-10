#include <stdio.h>
#define ROWS 3
#define COLS 5
void double_arr(double (*)[COLS], double (*)[COLS], int, int);
void display_2d(int m, int n, double array[m][n]);
int main(void)
{
	int i, j;
	double source[][COLS] = {
	{1.1, 1.2, 1.3, 1.4, 1.5},
	{2.1, 2.2, 2.3, 2.4, 2.5},
	{3.1, 3.2, 3.3, 3.4, 3.5}
	};
	double dob[][COLS] = {0};

	printf("source");
	display_2d(ROWS, COLS, source);
	double_arr(source, dob, ROWS, COLS);
	printf("dob");
	display_2d(ROWS, COLS, dob);
	return 0;
}

void double_arr(double (*arr1)[COLS], double (*arr2)[COLS], int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			*(*(arr2 + i) + j) = *(*(arr1 + i) + j) * 2;
}

void display_2d(int m, int n, double target[m][n])
{
	int r, c, l;
	printf("[%d][%d] = {\n", m, n);
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
