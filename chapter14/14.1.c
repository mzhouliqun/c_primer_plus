#include <stdio.h>
#include <ctype.h>
#include <string.h>

//char *s_gets(char *, int);
void trans(char *);
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
	int i = 0;
	int n = 0;
	char mh[10];

	printf("Please enter the month.\n");
//	s_gets(mh, 10);
	while (scanf("%s", &mh) != 1);
	trans(mh);
	for (i = 0; i < 12; i++)
	{
		if (strcmp(months[i].name, mh) != 0)
			continue;
		else
		{
			n = months[i].month_num;
			break;
		}
	}
	if (n)
		printf("%d\n",cal_days(n));
	else
		printf("Input error!\n");
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

/*char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}*/

void trans(char *str)
{
	int i = 1;
	*str = toupper(*str);
	while (*(str + i) != '\0')
	{
		*(str + i) = tolower(*(str + i));
		i++;
	}
}
