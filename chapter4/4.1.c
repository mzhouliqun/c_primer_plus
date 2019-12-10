#include <stdio.h>
#define LEN 20
int main(void)
{
	char first_name[LEN] = {'\0'};
	char last_name[LEN] = {'\0'};
	printf("Please input your first name:\n");
	scanf("%s", first_name);
	printf("Please input your last name:\n");
	scanf("%s", last_name);
	printf("%s, %s\n", first_name, last_name);
	return 0;
}
