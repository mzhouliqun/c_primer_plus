#include <stdio.h>
#define ROWS 3
#define COLS 5
void store(double (*)[COLS], int);
void display_2d(int, int, double (*)[COLS]);
double average_arr_2d(double (*)[COLS], int);
double average_subarr_1d(double (*), int);
double average_arr_2dtot(double (*)[COLS], int);
double max_arr(double (*)[COLS], int);
int main(void)
{
	int r, c;
	double array[ROWS][COLS] = {0};
	store(array, ROWS);
	display_2d(ROWS, COLS, array);
	average_arr_2d(array, ROWS);
	printf("The average of this array[3 x 5] is: %lf\n",average_arr_2dtot (array, ROWS));
	printf("The max value of this array[3 x 5] array is: %lf\n", max_arr (array, ROWS));
	return 0;
}

void store(double (*arr)[COLS], int rows)
{
	printf("Please input a \"[3 x 5]\" array:\n");
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			while (scanf ("%lf", &arr[i][j]) != 1)
			{
				printf("Input error, please try again!\n");
				scanf("%*s");
				continue;
			}
		}
	printf("Sub_arr[%d] Done!\n", i);
	}
}

void display_2d(int m, int n, double (*arr)[COLS])
{
	int r, c, l;
	printf("arr[%d][%d] = {\n", m, n);
	for (r = 0; r < m - 1; r++)
	{
		printf("{");
		for (c = 0; c < n - 1; c++)
			printf("%lf, ", arr[r][c]);
		printf("%lf},\n", arr[r][n - 1]);
	}
	printf("{");
	for (l = 0; l < n - 1; l++)
		printf("%lf, ", arr[m - 1][l]);
	printf("%lf}\n", arr[m - 1][n -1]);
	printf("};\n");
}

double average_arr_2d(double (*arr)[COLS], int rows)
{
	int i, j;
	double ave[ROWS] = {0};
	double cols = COLS;

	for (i = 0; i < rows; i++)
	{
		ave[i] = average_subarr_1d(*(arr + i), cols);
		
		printf("The average of Sub_arr[%d] is: %lf\n", i, ave[i]);
	}
}

double average_subarr_1d(double (*subarr), int cols)
{
	int i;
	double ave, tot;
	for (i = 0, tot = 0; i < cols; i++)
	{
		tot += *(subarr + i);
		ave = tot / cols;
	}
	return ave;
}

double average_arr_2dtot(double (*arr)[COLS], int rows)
{
	int i, j;
	double tot = 0;
	double ave;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			tot += *(*(arr + i) +j);
	ave = tot / (COLS *rows);
	return ave;
}

double max_arr(double (*arr)[COLS], int rows)
{
	int i, j;
	double value = **arr;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
		{
			if (value < *(*(arr + i) +j))
				value = *(*(arr + i) +j);
		}
	return value;
}

