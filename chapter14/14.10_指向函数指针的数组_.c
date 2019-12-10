#include <stdio.h>
#include <string.h>
#define MAXLEN 3
char showmenu(void);
void eatline(void);
void show(int (*cal)(int), int);
int second_power(int);
int third_power(int);
int fourth_power(int);
int main(void)
{
	int (*pfun[MAXLEN]) (int) = {second_power, third_power, fourth_power};
	int n;
	int result = 0;
	char choice;

	printf("Please input a integer (any non-numeric to quit):\n\n");
	while (scanf("%d", &n) == 1)
	{
		eatline();
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
				case 'a': result = pfun[0](n); break;
				case 'b': result = pfun[1](n); break;
				case 'c':
							if (n > 215 || n < -215)
							{
								printf("Outof range!\n");
								continue;
							}
							result = pfun[2](n); break;
				case 'n': break;
			}
			printf("Result: %d\n", result);
		}
		printf("\nPlease input a integer (any non-numeric to quit):\n\n");
	}
	printf("\nBye!\n");
	return 0;
}

char showmenu(void)
{
	char ans;
	printf("\nEnter your choice:\n");
	printf("a) second power\n");
	printf("b) third power\n");
	printf("c) fourth power\n");
	printf("n) next\n\n");
	ans = getchar();
	eatline();
	while (strchr("abcn", ans) == NULL)
	{
		printf("Input error! Please enter a 'a', 'b', 'c', 'n'\n");
		ans = getchar();
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while (getchar() != '\n');
}

int second_power(int n)
{
	return n * n;
}

int third_power(int n)
{
	return n * n * n;
}

int fourth_power(int n)
{
	return n * n * n * n;
}
