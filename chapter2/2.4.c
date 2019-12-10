#include <stdio.h>
void pmesg1(void);
void pmesg2(void);
int main(void)
{
	pmesg1();
	pmesg1();
	pmesg1();
	pmesg2();
	return 0;
}

void pmesg1(void)
{
	printf("For he\'s a jolly good fellow!\n");
}

void pmesg2(void)
{
	printf("Which nobody can deny!\n");
}
