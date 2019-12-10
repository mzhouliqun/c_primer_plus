#include <stdio.h>
#include <string.h>
#define SIZE 1001
void get_first_word(char *);
int main(void)
{
	char input[SIZE];
	char ch;

	puts("Please enter a line of text, the program will get the first word from your input.");
	gets(input);
	get_first_word(input);
	puts(input);
	return 0;
}

void get_first_word(char *str)
{
	int begin, end;
	for (begin = 0; isspace(*(str + begin)); begin++);
	for (end = begin; !isspace(*(str + end)); end++);
	*(str + end) = '\0';
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}
