#include <stdio.h>
#define SIZE 4
void arplus(int *, int *, int *, int);
void display(int *, int);
int main(void)
{
	int nums1[] = {2, 4, 5, 8};
	int nums2[] = {1, 0, 4, 6};
	int target[] = {0};

	arplus(nums1, nums2, target, SIZE);
	printf("nums1[%d] = {2, 4, 5, 8}\n", SIZE);
	printf("nums2[%d] = {1, 0, 4, 6}\n", SIZE);
	printf("\n");
	printf("The calculation results as follows:\n");
	printf("\n");
	printf("target[%d] = ", SIZE);
	display(target, SIZE);
	printf("\n");
	return 0;
}

void arplus(int *arr1, int *arr2, int *tar, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(tar + i) = *(arr1 + i) + *(arr2 + i);
}

void display(int *array, int m)
{
	int i;
	printf("{");
	for (i = 0; i < m - 1; i++)
		printf("%d, ", *(array + i));
	printf("%d}\n", *(array + m - 1));
}

