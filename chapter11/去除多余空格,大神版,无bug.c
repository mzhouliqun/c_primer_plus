#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *s_gets(char *str, int n);
char *del_space(char *str);
char *to_space(char *str);

int main(void)
{
	char temp[1001];

	s_gets(temp, 1001);
	char *p = del_space(to_space(temp));
	printf("%s\n", p);
	return 0;
}

char *del_space(char *str)
{
	int i = -1;
	int cur = 0;
	int j = strlen(str);
	char *fp = NULL;
	char *fp_temp = NULL;

	if (str == NULL)
		return "error";

	while (str[++i] == ' ');//去掉前后空格//前++在此处比较好控制好i的值
	while (str[--j] == ' ');
	for (; i <= j; ++i, ++cur)
		str[cur] = str[i];
	str[cur] = '\0';
	fp = fp_temp = str;//fp记录字符串，否则丢失；
	while (*str)
	{
		if (*str != ' ')
		{
			*fp_temp = *str;
			fp_temp++;
		}
		else
		{
			if (*(fp_temp - 1) != ' ')//只取一个空格
			{
				*fp_temp = *str;
				fp_temp++;
			}
		}
		str++;
	}
	*fp_temp = '\0';
	return fp;
}

char *to_space(char *str)
{
	int i = 0;
	int n = strlen(str);

	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (isspace(str[i]) && str[i] != ' ')
				str[i] = ' ';
			i++;
		}
	}
	return str;
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
