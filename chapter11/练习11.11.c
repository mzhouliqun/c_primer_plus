#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "Grant"
#define MAX 40
void trans(char *);
int main(void)
{
	char try[MAX];
	char answer[] = ANSWER;

	puts("Who is buried in Grant's tomb?");
	gets(try);
	trans(try);
	trans(answer);
	while (strcmp(try, answer) != 0)
	{
		puts("No, that's wrong. Try again.");
		gets(try);
		trans(try);
	}
	puts("That's right!");
	return 0;
}

void trans(char *str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
