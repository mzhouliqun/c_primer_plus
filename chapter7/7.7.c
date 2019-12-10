#include <stdio.h>
#define base_salary_rate 10
#define overtime_rate 1.5
#define value_1 300
#define value_2 150
#define tax_rate_1 0.15
#define tax_rate_2 0.2
#define tax_rate_3 0.25
int main(void)
{
	double work_hours, sum_salary, pretax_salary, tax;

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
	else if (pretax_salary > value_1 + value_2)
		tax = (pretax_salary - value_1 - value_2) * tax_rate_3 + (value_1 * tax_rate_1) + (value_2 * tax_rate_2);
	printf("total salary is %.3lf\n", pretax_salary);
	printf("tax is %.3lf\n", tax);
	printf("net salary is %.3lf\n", pretax_salary - tax);
	return 0;
}
