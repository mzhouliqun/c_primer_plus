#include <stdio.h>
#include <string.h>
int btoi(char *);
int main(void)
{
	char *pbin = "01001001";
	printf("%d\n", btoi(pbin));
	return 0;
}

int btoi(char *pbit)
{
	int len = (int) strlen(pbit);
	int ts = 1;
	int sum = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		sum  += (pbit[i] - 48) * ts;
		ts <<= 1;
	}
	return sum;
}
