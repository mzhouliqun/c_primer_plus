#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1001
int myatoi(char *);
void drop_space(char *);
void get_first_digit_str(char *);
void left_1(char *);
int cal(char *);
int power (int, int);
int main(void)
{
	int num;
	char string[SIZE];
	gets(string);
//	num = atoi(string);
	num = myatoi(string);
	printf("%d\n", num);

        return 0;
}

int myatoi(char *str)
{
	int sum;
	int pm = 1;
	drop_space(str);
	if (*str == '+')
	{
		left_1(str);
		if (!isdigit(*str))
			return 0;
		else
			get_first_digit_str(str);
	}	
	else if (*str == '-')
	{
		pm = -1;
		left_1(str);
		if (!isdigit(*str))
			return 0;
		else
			get_first_digit_str(str);
	}
	else if (!isdigit(*str))
		return 0;
	else
		get_first_digit_str(str);
	return(cal(str) * pm);
}

void drop_space(char *str)
{
        int begin, end;
        int i;
        for (begin = 0; isspace(*(str + begin)); begin++);
        for (end = begin; !isspace(*(str + end)); end++);
        for (; *(str + begin) != '\0'; str++)
                *str = *(str + begin);
        *str = '\0';
}

void left_1(char *str)
{
        int i;
        int len;
        len = strlen(str);
        for (; *(str + 1) != '\0';str++)
                *str = *(str + 1);
        *str = '\0';
}

void get_first_digit_str(char *str)
{
	int begin, end;
	for (begin = 0; isdigit (*(str + begin)); begin++);
	for (end = begin; !isdigit (*(str + end)); end++);
	*(str + begin) = '\0';
}

int cal(char *str)
{
        int i;
        int len;
        int sum = 0;
        int k;
        len = strlen(str);
        for (i = 0, k = len - 1; i < len; i++, k--)
                sum += ((*(str + i) - 48) * power(10, k));
        return sum;

}

int power(int m, int n)
{
        int i;
        int power = 1;

        for (i = 0; i < n; i++)
                power *= m;
        return power;
}
