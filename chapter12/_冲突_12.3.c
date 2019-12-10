#include <stdio.h>
void set_mode(int);
void  metric_mode(void);
void  US_mode(void);
int main(void)
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		printf("Eneter 0 for metric mode, 1 for US mode");
		printf("(-1 to quit):");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}

void set_mode(int num)
{
	if (num == 0)
		metric_mode();
	else if (num == 1)
		US_mode();
	else
	{
		if ((num % 2) == 0)
		{
			printf("Invalid mode specified. Mode 0 (metric) used.\n");
			metric_mode();
		}
		else
		{
			printf("Invalid mode specified. Mode 1 (US) used.\n");
			US_mode();
		}
	}
}

void metric_mode(void)
{
	double distance;
	double fuel;

	printf("Enter distance traveled in kilometers: ");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in liters: ");
	scanf("%lf", &fuel);
	printf("Fuel consumption is %.2lf liters per 100km.\n", fuel / (distance / 100));
}

void US_mode(void)
{
	double distance;
	double fuel;

	printf("Enter distance traveled in miles: ");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in gallons: ");
	scanf("%lf", &fuel);
	printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel);
}
