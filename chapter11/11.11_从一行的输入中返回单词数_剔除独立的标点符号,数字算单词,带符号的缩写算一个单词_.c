#include <stdio.h>
#include <string.h>
#define SIZE 1001
char *get_space(char *str);
void drop_space(char *str);
void get_first_word(char *str);
int if_first_char(char *str);
int check_space(char *str);
int rough_cal(char *str);
int main(void)
{
	int ifc;
	int cspace;
	int len;
	int roughcal;
	int words;
	int tmd = 0;
	char string[SIZE];
	gets(string);
	ifc = if_first_char(string);
	cspace = check_space(string);
	roughcal = rough_cal(string);
	words = roughcal + cspace - ifc;
	printf("You have entered the %d word(s).\n", words);
	return 0;
}

int if_first_char(char *str)
{
	int num;
	if (ispunct(str[0]))
	{
		int i = 0;
		int len;
		char temp[SIZE];
		strcpy(temp, str);
		char *cp;
		cp = temp;      
		get_first_word(cp);
		for (i = 0; *(cp + i) != '\0'; i++)
			if (!ispunct(*(cp + i)))
				break;
		len  = strlen(cp);
		if (i == len)
			num = 1;
		else
			num = 0;
	}
	else
		num = 0;
	return num;
}

int check_space(char *str)
{
	int len;
	int front = 0;
	int back = 0;
	int revise = 0;
	len = strlen(str);
	if (len == 0)
		revise = 0;
	else
	{
		if (isspace(*str))
			front++;
		if (isspace(*(str + len - 1)))
			back++;
		if ((front + back) == 0)
			revise = 1;
		else if ((front + back) == 1)
			revise = 0;
		else
			revise = -1;
	}
	return revise;
}

int rough_cal(char *str)
{
	int i;
	int count = 0;
	int punct = 0;
	char temp1[SIZE];
	char temp2[SIZE];
	char *cp;

	strcpy(temp1, str);
	cp = temp1;
	while (*(cp = get_space(cp)) != '\0')
	{
		if (isspace(*cp))
		{
			drop_space(cp);
			count++;
		}
		strcpy(temp2, cp);
		get_first_word(temp2);
		for (i = 0; i < strlen(temp2); i++)
			if (!ispunct(temp2[i]))
				break;
		if (i == strlen(temp2) && i != 0)
			punct++;
	}
	return(count - punct);
}

char *get_space(char *str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (isspace(*(str + i)))
			break;
		else
			i++;
	}
		return(str + i);
}

void drop_space(char *str)
{
	int begin, end;
	int i;
	for (begin = 0; isspace(*(str + begin)); begin++);
	for (end = begin; !isspace(*(str + end)); end++);
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}

void get_first_word(char *str)
{
	int begin, end;
	for (begin = 0; isspace(*(str + begin)); begin++);
	for (end = begin; !isspace(*(str + end)); end++);
	*(str + end) = '\0';
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}
