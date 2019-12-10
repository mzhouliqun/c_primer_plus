#include <stdio.h>
#define LEN 1001
void delspace(char *ps);
int main(void)
{
	char string[LEN] = "       8352293     4588832255 0887064507 5394739520 4396807906    ";

	delspace(string);
	printf("%s\n", string);
	return 0;
}

void delspace(char *ps)
{
	char *temp = ps;

	while (*ps != '\0')
	{
		if (*ps != ' ')
			*temp++ = *ps;
		ps++;
	}
	*temp = '\0';
}
