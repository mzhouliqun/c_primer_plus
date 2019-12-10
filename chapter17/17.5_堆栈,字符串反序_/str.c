#include <stdio.h>
#include "stack.h"

#define MAXLEN 100

char *s_gets(char *, int);

int main(void)
{
	Stack stack;
	Item ch;
	char string[MAXLEN];
	int i;

	InitializeStack(&stack);
	printf("Please input a string:\n");
	s_gets(string, MAXLEN);
	for(i = 0; string[i] != '\0' && i < MAXLEN; i++)
		Push(string[i], &stack);
	printf("\nOutput string from the stack:\n");
	while(Pop(&ch, &stack))
		putchar(ch);
	putchar('\n');
	return 0;
}

char *s_gets(char *str, int n)
{
	int i = 0;
	char *ret_val;

	ret_val = fgets(str, n, stdin);
	if (ret_val != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}
