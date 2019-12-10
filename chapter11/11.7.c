#include <stdio.h>
#include <string.h>
#define SIZE 1001
char drop_space_get_char(void);
char *string_in(char *, char *);
char *char_in(char * , char);
int main(void)
{
	char string1[SIZE];
	char string2[SIZE];
	char ch;
	char answer;

	do
	{
		printf("Please input string1:\n");
		gets(string1);
		printf("Please input string2:\n");
		gets(string2);
		if (string_in(string1, string2) == NULL)
			printf("NULL\n");
		else
			puts(string_in(string1, string2));
		printf("Enter any key to continue, except 'q':\n");
		answer = drop_space_get_char();
	}
	while (answer != 'q');
	return 0;
}

char drop_space_get_char(void)
{
        char ch;

	ch = getchar();
	while (getchar() != '\n');
        return ch;
}

char *string_in(char *str1, char *str2)
{
	char *t = str1;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i;
	int count;

	if (len1 < len2)
		return NULL;
	if (*str1 == '\0' || *str2 == '\0')
		return NULL;

	while ((t = char_in(str1, str2[0])) != NULL)
	{
		count = 0;
		if (strlen(t) < len2)
			return NULL;
		else
		{
			for (i = 0; i < len2; i++)
			{
				if (*(t + i) == *(str2 +i))
					count++;
				else
					break;
			}
				if (count == len2)
					return t;
		}
		str1 = t + 1;
	}
	return NULL;
}

char *char_in(char *str , char ch)
{
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		if (ch == *(str + i))
//			return(str + i);
			return &str[i];
	}
	return 0;
}
