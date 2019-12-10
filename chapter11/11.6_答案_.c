#include <stdio.h>
#include <string.h>
#define SIZE 91		//数组长度超过92有几率报错，超过93一定报错
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

/*char *mystrncpy(char *str1, char *str2, int num)
{
	int length_str1;
	int length_str2;
	int i = 0;
	int j;
	while (*(str1 + i) != '\0')
		i++;
	length_str1 = i;
	if ( length_str2 >= num)
	{
		*(str2 + num) = '\0';
		length_str2 = num;
	}
	else
		length_str2 = strlen(str2);
  	for (j = 0; j <= length_str2; j++)
  	*(str1 + length_str1 + j) = *(str2 + j);
  	return str1;
}*/  	

char *mystrncpy(char *p1, char *p2, int n)
{
        char *p = p1;
        while (*p1++ != '\0') continue;
        *--p1 = *p2;
        n--;
        while (n > 0 && *p2 != '\0')
        {
                *++p1 = *++p2;
                n--;
        }
        return p;
}
