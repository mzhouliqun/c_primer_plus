#include <stdio.h>
#include <string.h>
void outtemp(void); //丢弃缓冲区中的多余的输入
char *string_in(char *s1,char *s2); //查找字符串s2在s1中的位置，如果没有找到则返回空指针
char *string_inchar(char *s1,char ch); //查找一个字符是否在一个字符串中，如果在则返回这个字符所在位置地址，否则返回NULL
int main(void)
{
	char *s1 = "helllo";
	char temp[20];
	char *s2 = temp;
	char ch = 'y';
	while (1)
	{
		puts("请输入将要查找的字符串:");
		gets(s2);
		puts(string_in(s1,s2));
	}
	return 0;
}

char *string_in(char *s1,char *s2)
{
	int i;
	char *t = s1;
	if (s1 == NULL || s2 == NULL)
	return NULL;
	int n_s1 = strlen(s1);
	int n_s2 = strlen(s2);
	int k = 0;
	if (n_s1 < n_s2)
	return NULL;
	while ((t = string_inchar(s1,s2[0])) != NULL)
	{
		k = 0;
		if (strlen(t) < n_s2)
			return NULL;
		else
		{
			for (i = 0;i<n_s2;i++)
			{
				if (t[i] == s2[i])
					k++;
				else
					break;
			}
			if (k == n_s2)
				return t;
		}
		s1 = t + 1;
	}
	return NULL;
}
char *string_inchar(char *s1, char ch)
{
	int i;
	for (i = 0;i < strlen(s1); i++)
	{
		if (ch == s1[i])
			return &s1[i];
	}
	return NULL;
}
