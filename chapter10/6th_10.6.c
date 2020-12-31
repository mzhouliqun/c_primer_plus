#include <stdio.h>
#define LEN 10
void descend(double *);
void display(double *, int);
int main(void)
{
	double array[LEN] = {2.694, 83905.23, -0.393, 48.1, 0.0024, 997.3, -3419.3969, 976.11, 7.2, 17.8593};
	printf("original:\n\n");
	display(array, LEN);
	printf("\n");
	descend(array);
	printf("descended:\n\n");
	display(array, LEN);
	return 0;
}

void descend(double *arr)
{
	int i;
	int j;

	for (i = 0; i < LEN; i++)
	{
		for (j = i; j < LEN; j++)
		{
			double temp;
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void display(double arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%lf\n", arr[i]);
}
