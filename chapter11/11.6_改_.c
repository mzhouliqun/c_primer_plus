#include <stdio.h>
#include <string.h>
#define SIZE 1001
int get_int(void);
char drop_space_get_char(void);
char *mystrncpy(char *, char *, int);
int main(void)
{
	char string1[SIZE];
	char string2[SIZE];
	char ch;
	char answer;
	int len;

	do
	{
		printf("Please input string1:\n");
		gets(string1);
		printf("Please input string2:\n");
		gets(string2);
		printf("Please input the length of string you want to copy:\n");
		len = get_int();
		printf("after copying\n");
		puts(mystrncpy (string1, string2, len));
		printf("Enter any key to continue, except 'q':\n");
		answer = drop_space_get_char();
	}
	while (answer != 'q');
	return 0;
}

int  get_int(void)
{
	int input;
	char ch;

	while (scanf("%d", &input) != 1 || input < 0)
	{
		while ((ch = getchar()) != '\n')
			printf("Input error, try again!\n");
		if (input < 0)
		{
			printf("The value that you input must be larger than 0, try again!\n");
			continue;
		}
	}
	return input;
}

char drop_space_get_char(void)
{
        char ch;

        while (getchar() != '\n');
	ch = getchar();
	while (getchar() != '\n');
        return ch;
}

char *mystrncpy(char *str1, char *str2, int num)
{
	int i = 0;
	int j = 0;

	while (*(str1 + i) != '\0')
		i++;
	(strlen(str2) > num) ? *(str2 + num) = '\0' : *(str2 + strlen(str2));
	for (; j <= strlen(str2); j++)
		*(str1 + i + j) = *(str2 + j);
	return str1;
}
