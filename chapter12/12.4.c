#include <stdio.h>
int loop_count = 0;
int count(void);
char get_first_char(void);
int main(void)
{
	char ch;
	printf("Input 'q' to quit: ");
	while ((ch = get_first_char()) != 'q')
		printf("function has been called %d time(s)\n", count());
	return 0;
}
	
char get_first_char(void)
{
	char ch;
	ch = getchar();
	while (getchar() != '\n');
	return ch;
}

int count(void)
{
	loop_count++;
	return loop_count;
}
