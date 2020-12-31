#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
int *get_value(void);
char **foo(int);
int main(void)
{
	char temp[MAXLEN] = {'\0'};
	int *num;
	char **string;

	printf("How many words do you wish to enter?\n");
	num = get_value();
	printf("Enter %d words now:\n", *num);
	string = foo(*num);
	for (int i = 0; i < *num; i++)
	{
		scanf("%s", temp);
		string[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(string[i], temp);
	}
	printf("Here are your words:\n");
	for (int i = 0; i < *num; i++)
	{
		printf("%s\n", string[i]);
		free(string[i]);
	}
	free(num);
	free(string);
	return 0;
}

int *get_value(void)
{
	char ch = '\0';
	int *num;
	num = (int *)malloc(sizeof(int));

	while (scanf("%u", num) != 1)
	{
		if (ch = getchar() == EOF)
		{
			while (ch == EOF)
				ch = getchar();
			*num = 0;
			break;
		}
		while (ch != '\n' && ch != EOF )
			ch = getchar();
	}
	return num;
}

char **foo(int n)
{
	char **p = (char **)malloc(n * sizeof(char **));
	return p;
}

