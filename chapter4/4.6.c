#include <stdio.h>
#include <float.h>
int main(void)
{
	double numd = 1.0/3.0;
	float numf = 1.0/3.0;

	printf("numd: %.4lf %.12lf %.16lf\n", numd, numd, numd);
	printf("numf: %.4f %.12f %.16f\n", numf, numf, numf);
	printf("DBL_DIG: %d\n", DBL_DIG);
	printf("DBL_DIG: %d\n", FLT_DIG);
	return 0;
}

