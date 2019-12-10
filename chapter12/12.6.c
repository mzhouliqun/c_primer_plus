#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define DIV 10
#define COUNT 1000
void get_1000_rand(void);
int main(void)
{
	int i;

	for (i = 0; i < DIV; i++)
	{
		printf("Group %d:\n", i + 1);
		get_1000_rand();
		printf("======================\n");
		sleep(2);
	}
	return 0;
}

void get_1000_rand(void)
{
	int i;
	int temp;
	int num[DIV] = {0};
	srand((unsigned int) time (0));
	for (i = 0; i < COUNT; i++)
	{
		temp = rand() % DIV + 1;
		switch(temp)
		{
			case 1: num[0]++; break;
			case 2: num[1]++; break;
			case 3: num[2]++; break;
			case 4: num[3]++; break;
			case 5: num[4]++; break;
			case 6: num[5]++; break;
			case 7: num[6]++; break;
			case 8: num[7]++; break;
			case 9: num[8]++; break;
			case 10: num[9]++; break;
		}
	}
	for (i = 0; i < DIV; i++)
		printf("%d %10d\n",(i + 1), num[i]);
}
