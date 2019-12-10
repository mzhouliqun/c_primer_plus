#include <stdio.h>
#include <string.h>
#define SIZE 1001
void trans_seq(char *);
char get_first_char(void);
int main(void)
{
	char string[SIZE];
	char ch;
	char answer = '\0';
	do
	{
		printf("Please input your string:\n");
		gets(string);
		trans_seq(string);
		puts(string);
		printf("Enter any key to continue, except 'q':\n");
		answer = get_first_char();
	}
	while (answer != 'q');
	return 0;
}

char get_first_char(void)
{
        char ch;

	ch = getchar();
	while (getchar() != '\n');
        return ch;
}

void trans_seq(char *str)
{
	char temp; 
	int i;
	int len;
	for (len = 0; str[len] != '\0'; len++)	continue;
	len--;
//	for (i = 0; i < (len/2 + 1); i++)
	for (i = 0; i < (len - i); i++)
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}
	str[len + 1] = '\0';
}
