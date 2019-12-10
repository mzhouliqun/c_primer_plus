#include <stdio.h>
#include <time.h>
void delay(double time);
int main(void)
{
	double time;
	printf("input a time(in seconds) to delay(q to quit):");
	while( scanf("%lf",&time) == 1 )
	{
		delay(time);
		printf("time is out!\n");
		printf("input a time(in seconds) to delay(q to quit):");
	}
}

void delay(double time)
{
	double origin;
	origin = clock() / CLOCKS_PER_SEC ;
	while(clock() / CLOCKS_PER_SEC < (origin + time));
}
