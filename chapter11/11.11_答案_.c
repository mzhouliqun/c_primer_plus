#include <stdio.h>
int main(void)
{
	int word = 0;
	int upper = 0;
	int lower = 0;
	int punct = 0;
	int digit = 0;
	int begin = 0;
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			if (begin == 0)
			{
				word++;
				begin = 1;
			}
		}
		else begin = 0;
		if (isupper(ch)) upper++;
		if (islower(ch)) lower++;
		if (ispunct(ch)) punct++;
		if (isdigit(ch)) digit++;
	}
	printf("word: %10d\n", word);
	printf("upper: %10d\n", upper);
	printf("lower: %10d\n", lower);
	printf("punct: %10d\n", punct);
	printf("digit: %10d\n", digit);
	return 0;
}
