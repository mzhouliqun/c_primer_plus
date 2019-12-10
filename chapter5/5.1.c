#include <stdio.h>
int main(void)
{
	const int MIN_PER_HOUR = 60;
	int input_min;

	printf("Please enter the number of minutes(0 to quit):\n");
	scanf("%d", &input_min);
	while (input_min > 0)
	{
		printf("%d hour(s) %d minute(s)\n", input_min / MIN_PER_HOUR, input_min % MIN_PER_HOUR);
		printf("\nPlease enter the number of minutes(0 to quit):\n");
		scanf("%d", &input_min);
	}
	return 0;
}
