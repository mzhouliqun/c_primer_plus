#include <stdio.h>
#include <time.h>
void my_sleep(double);
int main(void)
{
	double num;

	printf("How many seconds do you want to pause?\n");
	while (scanf("%lf", &num) != 1)
	{
		getchar ();
		printf("Input error! Try again!\n");
	}
	printf("Pause %.2lf seconds:\n", num);
	my_sleep(num);
	return 0;
}

void my_sleep(double n)
{
	clock_t begin;
	long m;

	m = n * CLOCKS_PER_SEC;
	begin = clock();
	while ((clock() - begin) < m);
}
