#include <stdio.h>
int bin_dec(char *p);
char * pbin = "01001001";
int main(void)
{
	printf("bin: %s is dec: %d\n", pbin, bin_dec(pbin));
	return 0;
}

int bin_dec(char *p)
{
	int dec = 0;

	while (*p != '\0')
		dec = (dec <<1) + *p++ - '0' ;
	return dec;
}
