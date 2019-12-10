#include <stdio.h>
#include <string.h>
#define SIZE 1001
int get_space(char *);
void del_space(char *);
int main(void)
{
	char string[SIZE];
	char ch;
	do
	{
		printf("Please input your string:\n");
		gets(string);
    		del_space(string);
    		puts(string);
		printf("Enter any key to continue, except 'Enter':\n");
		gets(string);
	}
	while (*string != '\0');
	return 0;
}

void del_space(char *str)
{
	int i;
	int begin;
	int end;

	while (begin = get_space (str), *(str + begin) != '\0')
		for (i = begin; *(str + i) != '\0'; i++)
			*(str + i) = *(str + i + 1);
	end = get_space(str);
	*(str + end) = '\0';
}

int get_space(char *str)
{
        int i = 0;
        while (*(str + i) != '\0')
        {
                if (*(str + i) == ' ')
                        break;
                else
                        i++;
        }
        return i;
}
