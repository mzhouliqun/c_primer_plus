#include <stdio.h>
#define SIZE 255
int main(void)
{
	FILE *wp, *rp;
	char filename[SIZE] = "file.txt";
	int num = 8238201;
	int rnum;

	wp = fopen(filename, "w");
	fwrite(&num, sizeof (int), 1, wp);
	fclose(wp);
	rp = fopen(filename, "r");
	fread(&rnum, sizeof(int), 1, rp);
	fprintf (stdout, "%d", rnum);
	fclose(rp);
	return 0;
}
