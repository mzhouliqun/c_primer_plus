#include <stdio.h>
#define SIZE 1001
void input(int, char *);
int main(void)
{
	int num;
	char msg[SIZE];

	puts("Please input the char number of your string that you want to display:");
	while ((scanf("%d", &num)) != 1)
	{
		puts("Input error, please try again");
		scanf("%*s");
		continue;
	}
	printf("Please input something, program will display %d character(s):\n", num);
	gets(msg);
	input(num, msg);
	puts(msg);
	return 0;
}

void input(int n, char *str)
{
	int i;
	for (i = 0; i < n; i++)
		*(str + i) = getchar();
	*(str + i) = '\0';
}
