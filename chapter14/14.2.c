#include <stdio.h>
#include <string.h>

void get_day(void);
int get_month(void);
void get_year(void);
void cleanup(void);
void trans(char *);
int leap_year(int);
int cal_days(int);

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

union month_n {
	int m_n;
	char m_f[10];
	char m_s[3];
};

struct input {
	int day_input;
	union month_n month_input;
	int year_input;
};

struct input in = {.month_input.m_n = -9999};

int main(void)
{
	int value = 0;

	get_day();
	for (;;)
	{
		cleanup();
		value = get_month();
		if (value > 0 && value < 13)
			break;
		else
		{
			printf("Out of range! Try again!\n");
			in.month_input.m_n = -9999;
		}
	}
	get_year();
	if (leap_year (in.year_input))
		months[1].days = 29;
	printf("It is been %d day(s) since %s %d, %d.\n", cal_days (value) - (months[value - 1].days - in.day_input), months[value - 1].name, in.day_input, in.year_input);
	return 0;
}

void get_day(void)
{
	printf("Please input the number of the day:\n");
	while (scanf("%d", &in.day_input) != 1 || in.day_input < 1 || in.day_input > 31)
	{
		printf("Input error! The allowable range is 1 to 31. Please try again!\n");
		cleanup();
	}
}

int get_month(void)
{
	char temp[10];
	int i = 0;
	
	printf("Please input the month:\n");
	scanf("%d", &in.month_input);
	if (in.month_input.m_n  == -9999)
	{
		scanf("%s", temp);
		if (strlen(temp) == 3)
		{
			strcpy(in.month_input.m_s, temp);
			for (i = 0; i < 12; i++)
			{
				if (strcmp(months[i].brief, in.month_input.m_s) != 0)
					continue;
				else
					break;
			}
			i++;
		}
		else
		{
			trans(temp);
			strcpy(in.month_input.m_f, temp);
			for (i = 0; i < 12; i++)
			{
				if (strcmp(months[i].name, in.month_input.m_f) != 0)
					continue;
				else
					break;
			}
			i++;
		}
		return i;
	}
	return in.month_input.m_n;
}

void get_year(void)
{
	cleanup();
	printf("Please input the number of the year:\n");
	while (scanf("%d", &in.year_input) != 1 || in.year_input < 1970 || in.year_input > 3000)
	{
		printf("Input error! The allowable range is 1970 to 3000. Please try again!\n");
		cleanup();
	}
}

void cleanup(void)
{
	char ch;
	while ((ch = getchar()) != '\n');
}

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

int cal_days(int num)
{
	int tot = 0;
	int i;
	for (i = 0; i < num; i++)
		tot += months[i].days;
	return tot;
}

