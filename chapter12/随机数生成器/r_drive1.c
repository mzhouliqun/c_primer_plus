#include <stdio.h>
#include <time.h>
int mytime(void);
extern void srand1(unsigned int);
extern int rand1(void);
int main(void)
{
	unsigned seed;
	seed = (unsigned) mytime();
//	printf("%u\n", seed);
	srand1(seed);
	printf("%hd\n", rand1());
	return 0;
}

int mytime(void)
{
	int seconds = time((time_t *)NULL);
	return seconds;
}
