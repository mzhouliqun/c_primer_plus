#include <stdio.h>
#include <string.h>
#define LEN 1000
int main(void)
{
	char string[LEN] = {0};
	int str_len = 0;

	printf("Please input a word:\n");
	scanf("%s", string);
	str_len = strlen(string);
	for (int i = str_len; i > -1; i--)
		printf("%c", string[i]);
	printf("\n");
	return 0;
}
