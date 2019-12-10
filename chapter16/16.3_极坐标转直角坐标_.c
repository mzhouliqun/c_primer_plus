#include <stdio.h>
#include <math.h>

#define PI 4*atan(1)

struct polar {
	double radian;
	double length;
};

struct rectangular {
	double abscissa;
	double ordinate;
} rc;

struct rectangular *ptor (struct polar *);

int main(void)
{
	struct polar pc;
	struct rectangular *rcp;
	printf("Enter vector length and angle(q to quit):\n");
	while (scanf("%lf %lf", &pc.length, &pc.radian) == 2)
	{
		rcp = ptor(&pc);
		printf("\nResult:\n\n");
		printf("abscissa: %lf\n", rcp->abscissa);
		printf("ordinate: %lf\n", rcp->ordinate);
		printf("\nEnter vector length and angle(q to quit):\n");
	}
	return 0;
}

struct rectangular *ptor (struct polar *pp)
{

	rc.abscissa = ((pp->length) * cos((pp->radian * PI) / 180));
	rc.ordinate = ((pp->length) * sin((pp->radian * PI) / 180));
	return &rc;
}
