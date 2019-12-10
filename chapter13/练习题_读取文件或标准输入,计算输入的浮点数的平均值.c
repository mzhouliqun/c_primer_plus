#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	double n;
	double sum = 0;
	int ct = 0;
	if (argc == 1)
		fp = stdin;
	else if ( argc == 2 )
	{
		if ((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", argv[1]);
			exit(1);
		}
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(2);
	}
	while (fscanf(fp, "%lf", &n) == 1)
	{
		sum += n;
		ct++;
	}
	if ( ct > 0)
		printf("%lf\n", sum / ct);
	else
		printf("No data\n");
	fclose(fp);
	return 0;
}
