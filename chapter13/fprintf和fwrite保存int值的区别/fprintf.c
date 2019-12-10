#include <stdio.h>
#define SIZE 255
int main(void)
{
	FILE *wp;
	FILE *rp;
	char filename[SIZE] = "file.txt";
	char ch;
	int num = 8238201;

	wp = fopen(filename, "w");
	fprintf(wp, "%d", num);
	fclose(wp);
	rp = fopen(filename, "r");
	while ((ch = getc(rp)) != EOF)
		putc(ch,stdout);
	fclose(rp);
	return 0;
}
