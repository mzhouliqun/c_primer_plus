#include <stdio.h>
int main(void)
{
	char abc[26] = {0};
	int i = 0;
	
	for (; i < 26; i++)
		abc[i] = 'a' + i;
	for (i = 0; i < 25; i++)
		printf("%c ", abc[i]);
	printf("%c\n", abc[i]);
	return 0;
}
