#include <stdio.h>
int main(void)
{
	char ch;
	int count = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{
			ch = '!';
			putchar(ch);
			count++;
		}
		else if (ch == '!')
		{
			for (int i = 0; i < 2; i++)
				putchar(ch);
			count++;
		}
		else
			putchar(ch);
	}
	printf("The program was replaced %d times\n", count);
	return 0;
}
