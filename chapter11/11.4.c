#include <stdio.h>
#define SIZE 1001
char get_first_char(void);
char *search_char(char *, char);
int main(void)
{
	char string[SIZE];
	char ch;
	char answer;

	do
	{
		printf("Please enter a line of text:\n");
		gets(string);
		printf("Please enter a character:\n");
		ch = get_first_char();
		if (ch == '\n')
			ch = '\0';
		if (search_char(string, ch) == NULL)
			printf("NULL\n");
		else
			puts(search_char (string, ch));
		printf("Enter any key to continue, except 'q'\n");
		answer = get_first_char();
	} while (answer != 'q');
	return 0;
}

char get_first_char(void)
{
	char ch;

	ch = getchar();
	while (getchar() != '\n');
	return ch;
}

char *search_char(char *str, char ch)
{
	int i = 0;
	while (*(str + i) != ch)
	{
		if (*(str + i) != '\0')
			i++;
		else
			return NULL;
	}
	return(str + i);
}
