#include <stdio.h>
#include <time.h>
#define RANGE 1000
static unsigned int next = 1;
int mytime(void);
void srand1(unsigned int);
int rand1(void);
int main(void)
{
	unsigned seed;
	seed = (unsigned int) mytime();
	srand1(seed);
	printf("%hd\n", rand1());
	return 0;
}

int mytime(void)
{
	int seconds = time((time_t *)NULL);
	return seconds;
}

int rand1(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % RANGE;
}

void srand1(unsigned int seed)
{
	next = seed;
}
