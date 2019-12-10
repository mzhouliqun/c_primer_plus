#include <stdio.h>
void showmenu(void);
int getchoice(int, int);
int getint(void);
int main(void)
{

	int choice;

	showmenu();
	while ((choice = getchoice(1, 4)) != 4)
		printf("I like choice %d.\n", choice);	
	printf("Bye!\n");
	return 0;
}

void showmenu(void)
{
	printf("1) copy file		2) move files\n");
	printf("3) remove files		4) quit\n");
	printf("Enter the number of your choices: ");
}

int getchoice(int low, int high)
{

	int ans;
	ans = getint();
	while (ans < low || ans > high)
	{
		printf("%d is not a valid choice; please input again!\n", ans);
		showmenu();
		ans = getint();
	}
	return ans;
}

int getint(void)
{
	int kk;
	while (scanf("%d", &kk) != 1)
	{
		printf("Input error! Please input again: ");
                scanf("%*s");
                continue;
	}
	return kk;
}
