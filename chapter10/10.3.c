#include <stdio.h>
#define SIZE 5
int max(int [], int);
int main(void)
{

	int arr[SIZE] = {3, 2, 6, 1, 1};
	printf("the max value in arr[5] is %d\n", max (arr, SIZE));
	return 0;
}

max(int array[], int n)
{
	int i;
	int num;：
	num = array[0];
	
	for (i = 1; i < n; i++)
	{
		if (num <= array[i])
			num = array[i];
	}
	return num;
}
