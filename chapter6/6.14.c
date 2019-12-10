#include <stdio.h>
#include <string.h>
#define MAX 256
int main(void)
{
	char str[MAX] = {'\0'};
	int i = 0;
	int len;


	scanf("%c", &str[i]);
	i++;
	while (str[i - 1] != '\n' && i < (MAX - 1))
	{
		scanf("%c", &str[i]);
		i++;
	}
	str[i - 1] = '\0';

	len = strlen(str);
	printf("\nReverse sequence output:\n\n");
	for (i = len; i>= 0; i--)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}
