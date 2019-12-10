#include <stdio.h>
struct gas mpgs(struct gas);
void set_mpgs(struct gas *);
struct gas {
	double distance;
	double gals;
	double mpg;
};

struct gas mpgs(struct gas trip)
{
	if (trip.distance > 0 && trip.gals > 0)
		trip.mpg = trip.distance / trip.gals;
	else
		trip.mpg = -1.0;
	return trip;
}

void  set_mpgs(struct gas *ptrip)
{
	if (ptrip->distance > 0 && ptrip->gals > 0)
		ptrip->mpg = ptrip->distance / ptrip->gals;
	else
		ptrip->mpg = -1.0;
}
int main(void)
{
	putchar('\n');
	struct gas idaho = {430.0, 14.8};
	idaho = mpgs(idaho);
	printf("struct gas idaho = {430.0, 14.8};\n");
	printf("function mpgs idaho.mpg is %.2lf\n", idaho.mpg);

	putchar('\n');
	struct gas ohio = {583.0, 17.6};
	set_mpgs(&ohio);
	printf("struct gas ohio = {583.0, 17.6};\n");
	printf("function set_mpgs hoio.mpg is %.2lf\n", ohio.mpg);
	printf("\n");
	return 0;
}
