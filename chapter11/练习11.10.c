#include <stdio.h>
#define MSG "Make a difference!"
//#define MSG ""
char *space(char *);
int main(void)
{
	printf("%c", *space(MSG));
	return 0;
}

char *space(char *str)
{
	int i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return NULL;
	else
		return(str + i);
}
