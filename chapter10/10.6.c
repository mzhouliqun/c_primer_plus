#include <stdio.h>
#define ROWS 2
#define COLS 3
void copy_1d(double *, double *, int);
void copy_2d(double (*)[COLS], double (*)[COLS], int);
int main (void)
{
	int r, c;
	double source[ROWS][COLS] = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}};
	double target[ROWS][COLS] = {0};

	printf("source[%d][%d] = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}};\n", ROWS, COLS);
	copy_2d(source, target, ROWS);
	printf("target[%d][%d] = {", ROWS, COLS);
	printf("{");
	for (r = 0; r < COLS - 1 ; r++)
		printf("%.1lf, ", *(*(target + 0) + r));
	printf("%.1lf}, {", *(*(target + 0) + COLS-1));
	for (r = 0; r < COLS - 1; r++)
		printf("%.1lf, ", *(*(target + 1) + r));
	printf("%.1lf}}\n", *(*(target + 1) + COLS-1));
	return 0;
}

void copy_2d(double (*s_arr)[COLS], double (* t_arr)[COLS], int rows)
{
	int i;
	for (i = 0; i < rows; i++)
		copy_1d(*(s_arr + i), *(t_arr + i), COLS);
}

void copy_1d(double s[], double t[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(t + i ) = *( s + i);
}
