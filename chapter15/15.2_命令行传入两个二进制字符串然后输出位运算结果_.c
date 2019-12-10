#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_arg(char *);
int bstoi(char *);
char *itobs(int, char *);

int main(int argc, char *argv[])
{
	char bin_str[8 * sizeof(int) + 1];
	int istr1, istr2;
	int value;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [binary_string_1] [binary_string_2]\n", argv[0]);
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
	printf("[binary_1]             : %s\t\t%d\n", itobs(istr1 = bstoi(argv[1]), bin_str), istr1);
	printf("[binary_2]             : %s\t\t%d\n", itobs(istr2 = bstoi(argv[2]), bin_str), istr2);
	printf("\n");
	printf("[binary_1] & [binary_2]: %s\t\t%d\n", itobs((istr1 & istr2), bin_str), istr1 & istr2);
	printf("[binary_1] | [binary_2]: %s\t\t%d\n", itobs((istr1 | istr2), bin_str), istr1 | istr2);
	printf("[binary_1] ^ [binary_2]: %s\t\t%d\n", itobs((istr1 ^ istr2), bin_str), istr1 ^ istr2);
	printf("\n");
	printf("~[binary_1]            : %s\t\t%d\n", itobs(~istr1, bin_str), ~istr1);
	printf("~[binary_2]            : %s\t\t%d\n", itobs(~istr2, bin_str), ~istr2);
	return 0;
}

int check_arg(char *str)
{
	int len = (int) strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] != '1' && str[i] != '0')
			return 1;
	}
	return 0;
}

int bstoi(char *p)
{
	int num = 0;

	while (*p != '\0')
		num = (num << 1) + *p++ - '0';
	return num;
}

char *itobs(int n, char *ps)
{
	int i;
	static int size = 8 * sizeof(int);

	for (i = size -1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	return ps;
}
