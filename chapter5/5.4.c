#include <stdio.h>
#define INCH 2.54
#define FEIN 12
int main(void)
{
	double dnum;
	double inum;
	
	printf("Enter a height in centimeters: ");
	scanf("%lf", &dnum);
	while (dnum > 0)
	{
		inum = dnum / INCH;
		printf("%.2lf cm = %d feet, %.2lf inches\n", dnum, (int)(inum / FEIN), inum - ((int)(inum / FEIN) * FEIN));
		printf("Enter a height in centimeters(0 to quit): ");
		scanf("%lf", &dnum);
	}
	printf("bye\n");
	return 0;
}
