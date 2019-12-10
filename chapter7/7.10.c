#include <stdio.h>
#define threshold1 17850
#define threshold2 23900
#define threshold3 29750
#define threshold4 14875
#define rate 0.15
#define overate 0.28
void menu1(void);
double menu2(double);
int main(void)
{
	char option;
	int  num;
	double tax, salary, input;
	while (1)
	{
		menu1();
		while ((option = getchar()) == '\n') continue;
			switch (option)
			{
				case '1': num = threshold1; break;
				case '2': num = threshold2; break;
				case '3': num = threshold3; break;
				case '4': num = threshold4; break;
				case '5': return 0;
				default: printf("Input error, please input again!\n"); continue;
			}
			salary = menu2(input);
			if (salary <= num)
				tax = salary * rate;
			else
				tax = (salary - num) * overate + num * rate;
			printf("You should hand in taxes for %.2lf yuan.\n", tax);
	}
	return 0;
}

void menu1()
{
	printf("*****************************************************************\n");
	printf("Select the type of marriage\n");
	printf("1)SINGLE			2)HOST\n");
	printf("3)MARRIED_SHARE			4)MARRIED_DIVORCE\n");
	printf("5)quit\n");
	printf("*****************************************************************\n");
}
double menu2(double salary)
{
	double income;	
	printf("Please enter your income:\n");
	scanf("%lf", &income);
	return income;
}
