#include <stdio.h>
#define SIZE 5
void copy_arr(double [], double [], int);
void copy_ptr(double *, double *, int);
int main(void)
{

	int tr;
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[SIZE];
	double target2[SIZE];
	copy_arr(source, target1, SIZE);
	copy_ptr(source, target2, SIZE);
	printf("target1[SIZE] = {");
	for (tr = 0; tr < SIZE - 1; tr++)
	{
		printf("%.1lf", target1[tr]);
		printf(",");
		printf(" ");
	}
	printf("%.1lf", target1[SIZE - 1]);
	printf("}");
	printf("\n");
	printf("target2[SIZE] = {");
	for (tr = 0; tr < SIZE - 1; tr++)
	{
		printf("%.1lf", *(target2 + tr));
		printf(",");
		printf(" ");
	}
	printf("%.1lf", *(target2 + SIZE -1));
	printf("}");
	printf("\n");
	return 0;
}

void copy_arr(double source[], double target1[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		target1[i] = source [i];
}

void copy_ptr(double source[], double target2[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(target2 + i) = *(source + i);
}
