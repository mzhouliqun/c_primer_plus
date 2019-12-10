#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define RANGE 1000
static unsigned int next = 1;
int mytime(void);
void srand1(unsigned int);
int rand1(void);
double cal(void);
int main(void)
{
	printf("%lf\n", cal());
	return 0;
}

double cal(void)
{
	int m;
	int n;

	unsigned seed;
	seed = (unsigned int) mytime();
	srand1(seed);
	m = rand1();
	sleep(1);
	n = rand1();
	return((double) m / (double) n);
}

int mytime(void)
{
        int seconds = time((time_t *)NULL);
        return seconds;
}

int rand1(void)
{
	next = next * 1103515245 + 12345;
	return((unsigned int) (next / 65536) % RANGE);
}

void srand1(unsigned int seed)
{
	next = seed;
}
