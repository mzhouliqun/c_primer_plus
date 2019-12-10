#include <stdio.h>
void chline(char, int, int);
int getint(void);
int main(void)
{

	int number, line;
	char ch;

	printf("Input a character:\n");
	while (scanf("%c", &ch) != 1)
	{
		printf("Input error, please try again!\n");
		continue;
	}
	printf("Please input the number of characters to print:\n");
	number = getint();
	printf("Please input the number of lines:\n");
	line = getint();
	chline(ch, number, line);
	return 0;
}

int getint(void)
{
	int num;
	while (scanf("%d", &num) != 1)
	{
		printf("Input error! Please input again\n");
		scanf("%*s");
		continue;
	}
	return num;
}

void chline(char r, int s, int t)
{
	int count, line;
	for (line = 1; line <= t; line++)
	{
		for (count = 1; count <= s; count++)
			printf("%c", r);
		printf("\n");
	}
}
