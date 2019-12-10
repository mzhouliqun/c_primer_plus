#include <stdio.h>
#include "pe12-2a.h"
static int sp;
static double distance;
static double fuel;
void set_mode(int md)
{
	if (md == 0)
		sp = 0;
	else if (md == 1)
		sp = 1;
	else
	{
		if ((md % 2) ==  1)
		{
			sp = 1;
			printf("Invalid mode specified. Mode 1 (US) used.\n");
		}
		else
		{
			sp = 0;
			printf("Invalid mode specified. Mode 0 (metric) used.\n");
		}
	}
}

void get_info(void)
{
	if (sp == 0)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf", &fuel);
	}
	if (sp == 1)
	{
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%lf", &fuel);
	}
}

void show_info(void)
{
	if (sp == 0)
		printf("Fuel consumption is %.2lf liters per 100km.\n", fuel / (distance / 100));
	if (sp == 1)
		printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel);
}
