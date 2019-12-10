#include <stdio.h>
#define PRINCIPAL 100
#define INCREASE_RATE 0.08
#define DISBURSEMENT 10
int main(void)
{
	int i = 0;
	double assets = PRINCIPAL;

	for (i = 1; assets > 0; i++)
	{
		assets *= (1 + INCREASE_RATE);
		assets -= DISBURSEMENT;
	}
	printf("Chuckie's assets are %lf after %d years.\n", assets, i);
	return 0;
}
