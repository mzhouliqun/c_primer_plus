#include <stdio.h>
#define LEN 1001
void delspace(char *ps);
char *s_gets(char *str, int n);
int main(void)
{
	char string[LEN] = {'\0'};

	s_gets(string, LEN);
	delspace(string);
	printf("%s\n", string);
	return 0;
}

void delspace(char *ps)
{
	char *temp = ps;

	while (*ps != '\0')
	{
		if (*ps != ' ')
			*temp++ = *ps;
		ps++;
	}
	*temp = '\0';
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
