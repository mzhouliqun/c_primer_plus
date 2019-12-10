#include <stdio.h>

struct month {
	char name[10];
	char brief[4];
	int days;
	int month_num;
};

struct month months[12] = {
	{"January", "jan", 31, 1},
	{"February", "feb", 28, 2},
	{"March", "mar", 31, 3},
	{"April", "apr", 30, 4},
	{"May", "may", 31, 5},
	{"June", "jun", 30, 6},
	{"July", "jul", 31, 7},
	{"Auguest", "aug", 31, 8},
	{"September", "sep", 30, 9},
	{"October", "oct", 31, 10},
	{"November", "nov", 30, 11},
	{"December", "dec", 31, 12}
};

int cal_days(int);

int main(void)
{
	int n;

	printf("Please intput the month number:\n");
	while (1)
	{
		while (scanf("%d", &n) != 1)
		{
			scanf("%*s");
			continue;
		}
		if (n < 1 || n > 12)
		{
			printf("Out of range.\n");
			continue;
		}
		else
			break;
	}
	printf("%d\n", cal_days(n));
	return 0;
}

int cal_days(int num)
{
	int tot = 0;
	int i;

	for (i = 0; i < num; i++)
		tot += months[i].days;
	return tot;
}
