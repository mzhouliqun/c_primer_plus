#include <stdio.h>
#define DAYS_PER_WEEK 7
int main(void)
{
	int days;
	printf("Please input the number of days(0 to quit):\n");
	scanf("%d", &days);
	while (days > 0)
	{
		printf("%d days are %d weeks, %d days.\n", days, days / DAYS_PER_WEEK, days % DAYS_PER_WEEK);
		printf("\nPlease input the number of days(0 to quit):\n");
		scanf("%d", &days);
	}
	return 0;
}
