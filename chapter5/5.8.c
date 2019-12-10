#include <stdio.h>
void temperature(double);
int main(void)
{
	double fah;
	printf("please input a Fahrenheit temperature values(input q or non-number to quit\n");
	while (scanf("%lf", &fah) == 1)
		temperature(fah);
}

void temperature(double fah)
{
	double cel;
	double kel;
	const double xishu = 1.8;
	const double changshu_cf = 32.0;
	const double changshu_kc = 273.16;
	cel = (fah - changshu_cf) / xishu;
	kel = cel + changshu_kc;

	printf("%.2lf degrees Fahrenheit equal %.2lf degrees Celsius, equal %.2lf degrees Kelvin.\n", fah, cel, kel);
}
