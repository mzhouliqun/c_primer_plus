#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1001

void drop_space(char *str);
void get_first_word(char *str);
char *s_gets(char *str, int n);
void left(char *str, int n);
char *format_space(char *str);

int main(void)
{
	char temp[SIZE];
	char *str;

	s_gets(temp, SIZE);
	str = format_space(temp);
	printf("%s\n", str);
	free(str);
	return 0;
}


char *format_space(char *str)
{
	char str1[SIZE] = {'\0'};
	char str2[SIZE] = {'\0'};
	char *str3;

	str3 = (char *)malloc(sizeof(str1));
	strcpy(str1, str);

	while (strlen(str1) > 0)
	{
		drop_space(str1);
		strcpy(str2, str1);
		get_first_word(str2);
		left(str1, strlen(str2));
		if (*str2 != '\0')
		{
			strcat(str3, " ");
			strcat(str3, str2);
		}
	}
	drop_space(str3);
	return str3;
}

void drop_space(char *str)
{
	int begin;
	int i;

	for (begin = 0; isspace(*(str + begin)); begin++);
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}

void get_first_word(char *str)
{
	int begin, end;
	for (begin = 0; isspace(*(str + begin)); begin++);
	for (end = begin; !isspace(*(str + end)); end++);
	*(str + end) = '\0';
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}

char *s_gets(char *str, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(str, n, stdin);
	if (ret_val != NULL)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void left(char * str, int n)
{
        for (; *(str + n) != '\0';str++)
                *str = *(str + n);
        *str = '\0';
}
