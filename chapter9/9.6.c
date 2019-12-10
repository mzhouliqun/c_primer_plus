#include <stdio.h>
#include <ctype.h>
int alphabet(char);
int main(void)
{
	char ch;

	printf("Please input a letter:\n");
	scanf("%c", &ch);
	printf("The position of ABC is %d\n", alphabet(ch));
	return 0;
}

int alphabet(char letter)
{
	int value;
		if (isalpha(letter))
		{
			if (islower(letter))
				value = letter - 96;	
			else
				value = letter - 64;
		}
		else
			value = -1;
	return value;
}
