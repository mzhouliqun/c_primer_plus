#include <stdio.h>
int main(void)
{

	char response;
	int min = 1;
	int max = 100;
	int guess;

	guess = (max + min) / 2;
	printf("Pick an integer for 1 to 100. I will try to guess ");
	printf("it .\nRespond with a y if my guess is right and with");
	printf("\nan n if it is wrong.\n");
	printf("With a h if it is high, with a l if it is low.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response = getchar()) != 'y')
	{
		if (response == '\n')
			continue;
		if (response != 'l' && response != 'h')
		{
			printf("With a h if it is high, with a l if it is low.\n");
			continue;
		}
		else if (response == 'h')
			max = guess - 1;
		else
			min = guess + 1;
			guess = (max + min) / 2;
		printf("Uh...is your number %d?\n", guess);
	}
	printf("I knew I could do it!\n");
	return 0;
}
