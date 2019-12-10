#include <stdio.h>
#define LEN 20
int main(void)
{
	char name[LEN] = {0};
	double tall = .0;

	printf("Please input your name:\n");
	scanf("%s", name);
	printf("Please input your height:\n");
	scanf("%lf", &tall);
	printf("%s your are %.3lf feet tall\n", name, tall);
	return 0;
}
