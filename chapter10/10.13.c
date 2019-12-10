#include <stdio.h>
#define ROWS 3
#define COLS 5
void store(int m, int n, double arr[m][n]);
void display_2d(int m, int n, double arr[m][n]);
double average_arr_2d(int m, int n, double arr[m][n]);
double average_subarr_1d(int n, double subarr[n]);
double average_arr_2dtot(int m, int n, double [m][n]);
double max_arr(int m, int n, double [m][n]);
int main(void)
{
	int r = ROWS;
	int c = COLS;
	double array[ROWS][COLS] = {0};
	store(r, c, array);
	display_2d(r, c, array);
	average_arr_2d(r, c, array);
	printf("The average of this array[3 x 5] is: %lf\n",average_arr_2dtot (r, c, array));
	printf("The max value of this array[3 x 5] array is: %lf\n", max_arr (r, c, array));
	return 0;
}

void store(int m, int n, double arr[m][n])
{
	printf("Please input a \"[3 x 5]\" array:\n");
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			while (scanf("%lf", &arr[i][j]) != 1)
			{
				printf("Input error, please try again!\n");
				scanf("%*s");
				continue;
			}
		}
	printf("Sub_arr[%d] Done!\n", i);
	}
}

void display_2d(int m, int n, double arr[m][n])
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

double average_arr_2d(int m, int n, double arr[m][n])
{
	int i, j;
	double ave[ROWS] = {0};

	for (i = 0; i < m; i++)
	{
		ave[i] = average_subarr_1d(n, *(arr + i));
		printf("The average of Sub_arr[%d] is: %lf\n", i, ave[i]);
	}
}

double average_subarr_1d(int n, double subarr[n])
{
	int i;
	double ave, tot;
	for (i = 0, tot = 0; i < n; i++)
	{
		tot += *(subarr + i);
		ave = tot / n;
	}
	return ave;
}

double average_arr_2dtot(int m, int n, double arr[m][n])
{
	int i, j;
	double tot = 0;
	double ave;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			tot += *(*(arr + i) +j);
	ave = tot / (m * n);
	return ave;
}

double max_arr(int m, int n, double arr[m][n])
{
	int i, j;
	double value = **arr;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (value < *(*(arr + i) +j))
				value = *(*(arr + i) +j);
		}
	return value;
}

