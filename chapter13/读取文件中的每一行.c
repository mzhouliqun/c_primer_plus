#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
int main(int argc, char *argv[])
{
	FILE *fp;
	long i = 0L;
	char line[SIZE];

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(1);
	}
	while ((fgets(line, SIZE, fp)) != NULL)
		fputs(line, stdout);
	fclose(fp);
	return 0;
}

