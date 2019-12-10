#include <stdio.h>
int leap_year(int);
int main(void)
{
	int year;
	do
	{
		scanf("%d", &year);
		printf("%d\n", leap_year(year));
	}
	while (year > 0);
	return 0;
}

int leap_year(int n)
{
	if (n % 4)
		return 0;
	else
	{
		if (n % 100)
			return 1;
		else
		{
			if (n % 400)
				return 0;
			else
				return 1;
		}
	}
}
