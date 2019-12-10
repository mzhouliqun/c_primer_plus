#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int show_bit(int, int);
int check_arg(char *str);
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [integer] [positive_integer]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++)
	{
		if (check_arg(argv[i]))
		{
			fprintf(stderr, "Argument error!\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("%d\n", show_bit(atoi (argv[1]), atoi (argv[2])));
	return 0;
}

int show_bit(int n, int p)
{
	return 1 & (n >>= p);
}

int check_arg(char *str)
{
	int len = (int) strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(str[i]))
		return 1;
	}
	return 0;
}
