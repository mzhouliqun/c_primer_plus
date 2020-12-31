#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 10
#define MAXLEN 1001
char *s_gets(char *, int);
void get_first_word(char *, int);
int main(void)
{
	char input[MAXLEN];
	char ch;

	puts("Please enter a line of text, the program will get the first word from your input.");
	get_first_word(input, LEN);
	puts(input);
	return 0;
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

void get_first_word(char *sp, int n)
{
	char *str;
	str = s_gets(sp, n);
	int begin, end;
	for (begin = 0; isspace(*(str + begin)); begin++);
	for (end = begin; !isspace(*(str + end)); end++);
	*(str + end) = '\0';
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}
