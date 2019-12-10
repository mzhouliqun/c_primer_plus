#include <stdio.h>
#include <ctype.h>
#define STOP '#'
int main(void)
{
	char c;
	long n_other_character = 0L;
	int n_space_character = 0;
	int n_newline_character = 0;

	printf("Enter text to be analyzed('#' to terminate):\n");
	while ((c = getchar()) != STOP)
	{
		if (c == ' ')
			n_space_character++;
		else if (c == '\n')
			n_newline_character++;
		else
			n_other_character++;
	}
	printf("Space_character: %d\nNewline_character: %d\nOther_character: %ld\n", n_space_character, n_newline_character, n_other_character);
	return 0;
}
