#include <stdio.h>
#define SIZE 6
double max(double *, int);
int main(void)
{

	double arr[] = {4.3, 5.3, 2.6, 9.2, 2.8, 3.6};
	printf("The max value in arr[%d] is %.1lf\n", SIZE, max(arr, SIZE));
	return 0;
}

double max(double *arr, int n)
{
	double num;
	int i;
	for (i = 0, num = *arr; i < n; i++)
	{
		if (num <= *(arr + i))
			num = *(arr + i);
	}
	return num;
}

