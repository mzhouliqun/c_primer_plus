#include <stdio.h>
#include <string.h>
void my_strcat(char *str1, char *str2);
int main(void)
{
	char str1[] = "Hello";
	char str2[] = " world!";

	my_strcat(str1, str2);
	printf("%s\n", str1);
	return 0;
}

void my_strcat(char *str1, char *str2)
{
	int i, j;
	int k = 0;

	while (str1[k] != '\0')
		k++;

	for (i = k, j = 0; str2[j] != '\0'; i++, j++)
		str1[i] = str2[j];
}
