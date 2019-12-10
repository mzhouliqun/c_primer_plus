#include <stdio.h>
#define SIZE 1001
char get_first_char(void);
int is_witlun(char, char *);
void judge(int);
int main(void)
{
	char string[SIZE];
	char ch;
	char answer;
	do
	{
		printf("Please enter your string:\n");
		gets(string);
		printf("Please enter the character that you want to search:\n");
		ch = get_first_char();
		judge(is_witlun (ch, string));
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

int is_witlun(char ch, char *str)
{
	int count = 0;
	for (; *str != '\0'; *str++)
	{
		if (*str == ch)
			count++;
	}
	return count;
}

void judge(int times)
{
	if (!times)
		printf("Can not find any character in your string.\n");
	else
		printf("Find! Your character has appeared %d time(s).\n", times);
}

