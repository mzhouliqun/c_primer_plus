#include <stdio.h>
#include <string.h>
#define LEN 100
int main(void)
{
	char first_name[LEN];
	char last_name[LEN];
	int len_first;
	int len_last;

	printf("Please input your first name:\n");
	scanf("%s", first_name);
	printf("Please input your last name:\n");
	scanf("%s",  last_name);
	len_first = strlen(first_name);
	len_last = strlen(last_name);
	printf("%s %s\n", first_name, last_name);
	printf("%*d %*d\n",len_first, len_first, len_last, len_last);
	printf("%s %s\n", first_name, last_name);
	printf("%-*d %-*d\n",len_first, len_first, len_last, len_last);
	return 0;
}
