#include <stdio.h>
#define overtime_rate 1.5
#define value_1 300
#define value_2 150
#define tax_rate_1 0.15
#define tax_rate_2 0.2
#define tax_rate_3 0.25
void tssr(void);
int main(void)
{
    
	double work_hours, pretax_salary, tax, base_salary_rate;
	int choice;
	tssr();
	while (scanf("%d", &choice) != 0)
	{
		switch (choice)
		{
			case 1: base_salary_rate = 8.75; break;
			case 2: base_salary_rate = 9.33; break;
			case 3: base_salary_rate = 10.00; break;
			case 4: base_salary_rate = 11.20; break;
		}
		if (choice < 5)
		{
			printf("You have choose pay rate is %.2lf\n", base_salary_rate);
			printf("Please input your work hours a week:");
			while (1)
			{
				scanf("%lf", &work_hours);
				if (work_hours < 0)
					continue;
				else if (work_hours >= 0 && work_hours <= 40)
				{
					pretax_salary = base_salary_rate * work_hours;
					break;
				}
				else
				{
					pretax_salary = (40 + (work_hours - 40) * overtime_rate) * base_salary_rate;
					break;
				}
			}
			if (pretax_salary <= value_1)
				tax = pretax_salary * tax_rate_1;
			else if (pretax_salary > value_1 && pretax_salary <= value_1 + value_2)
				tax = (pretax_salary - value_1) * tax_rate_2 + (value_1 * tax_rate_1);
			else //if (pretax_salary > value_1 + value_2)
				tax = (pretax_salary - value_1 - value_2) * tax_rate_3 + (value_1 * tax_rate_1) + (value_2 * tax_rate_2);
			printf("total salary is %.3lf\n", pretax_salary);
			printf("tax is %.3lf\n", tax);
			printf("net salary is %.3lf\n", pretax_salary - tax);
		}
		else if (choice == 5)
			break;
		else
			printf("Input error, please input again!\n");
			tssr();
	}
	return 0;
}
void tssr(void)
{
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1)$8.75/hr                      2)$9.33/hr\n");
	printf("3)$10.00/hr                     4)$11.20/hr\n");
	printf("5)quit\n");
	printf("*****************************************************************\n\n");
}
