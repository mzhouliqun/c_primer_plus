#include <stdio.h>
int main(void)
{
	char uc;
	int rows;
	int i;
	int j;
	int k;
	int l;

	printf("Please enter an uppercase character, this program will print a pyramid of uppercase characters:\n");
	while (scanf("%c", &uc) < 0 || uc < 65 || uc > 90)
	{
		while (getchar() != '\n');
		printf("Input error!\n");
	}
	rows = uc - 'A' + 1;
	for (i = 0; i < rows; i++)
	{
		for (j = uc - 'A'; j > i; j--)
			printf(" ");
		for (k = 'A'; k <= 'A' + i; k++)
			printf("%c", k);
		for (l = k - 2; l >= 'A'; l--)
			printf("%c", l);
		printf("\n");
	}
	return 0;
}
