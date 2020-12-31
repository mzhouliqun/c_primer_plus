#include <stdio.h>
void calculate(double);
int main(void)
{
	double cups = 0;
	char ch;

	printf("Please enter the number of cups: \n");
	while (scanf("%lf", &cups) != 1)
	{
		if (ch = getchar() == EOF)
		{
			while (ch == EOF)
				ch = getchar();
			break;
		}
		while (ch != '\n' && ch != EOF)
			ch = getchar();
	}
	calculate(cups);
	return 0;
}

void calculate(double n)
{
	printf("\n%lf cpu(s) equal to:\n\n", n);
	printf("%lf pint(s)\n", 0.5 * n);
	printf("%lf ounce(s)\n", 8 * n);
	printf("%lf spoon(s)\n", 8 * 2 * n);
	printf("%lf teaspoon(s)\n", 8 * 2 * 3 * n);
}
