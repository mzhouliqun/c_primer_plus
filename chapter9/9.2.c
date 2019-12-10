#include <stdio.h>
int getint(void);
void chline(char, int, int);
int main(void)
{
	int i, j;
	char ch;

	printf("Please enter a character and two integers\n");
	printf("Character:\n");
	scanf("%c", &ch);
	printf("First integer:\n");
	i = getint();
	printf("Sceond integer\n");
	j = getint();	
	chline(ch, i, j);
	return 0;
}

void chline(char ch, int num1, int num2)
{
	int i, j, min, max;
	if (num1 < num2)
		min = num1, max = num2;
	else
		min = num2, max = num1;
	for (i = 1; i < min; i++)
		printf("%c", ' ');
	for (j = (max - min + 1); j > 0 && (max - min) >= 0 ; j--)
		printf("%c", ch);
	printf("\n");
}

int getint(void)
{
	int kk;
	while (scanf("%d", &kk) != 1)
	{
		printf("Input error! Please intput again\n");
		scanf("%*s");
		continue;
	}
	return kk;
}
