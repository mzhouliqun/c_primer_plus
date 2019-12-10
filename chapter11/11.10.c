#include <stdio.h>
#include <string.h>
#define LIM 10
#define SIZE 1001
void display_menu(void);
char get_first_char(void);
void display_string(char *[], int);
void original_string(char *[], int);
void ascii_string(char *[], int);
void len_string(char *[], int);
void word_string(char *[], int);
int len_word(char *);
int main(void)
{
	char string[LIM][SIZE];
	char *pt_original[LIM];
	char *pt_ascii[LIM];
	char *pt_len[LIM];
	char *pt_word[LIM];
	char select;
	int count = 0;
	int i;

	printf("Hello! Please input strings (up to 10), press [Ctrl] + [D] to complete.\n");
	while (count < LIM && gets (*(string + count)) != NULL && string[count][0] != '\0')
	{
		pt_original[count] = string[count];
		pt_ascii[count] = string[count];
		pt_len[count] = string[count];
		pt_word[count] = string[count];
		count++;
	}
	do
	{
		display_menu();
		printf ("Please enter your options: ");
		switch(select = get_first_char())
		{
			case 'a': original_string(pt_original, count); break;
			case 'b': ascii_string(pt_ascii, count); break;
			case 'c': len_string(pt_len, count); break;
			case 'd': word_string(pt_word, count); break;
			case 'q': puts("Quit."); break;
			default: puts("Input error, please input your options with 'a', 'b', 'c', 'd', 'e', 'q'."); break;
		}
	}
	while(select != 'q');
	return 0;
}

void display_string(char *sp[], int num)
{
	int i;
	for (i = 0; i < num; i++)
		puts(sp[i]);
}

void display_menu(void)
{
	puts("*********************************************");
	putchar('\n');
	puts("a. display originally.");
	puts("b. display in order of ascii.");
	puts("c. display in order of string's length.");
	puts("d. display in order of first word's length.");
	puts("q. quit.");
	putchar('\n');
	puts("*********************************************");
}

char get_first_char(void)
{
	char ch;
	ch = getchar();
	while (getchar() != '\n');
	return ch;
}

void original_string(char *str[], int num)
{
	puts("display originally:");
	display_string(str, num);
}

void ascii_string(char *str[], int num)
{
	char *temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if ((strcmp(str[top], str[seek]) > 0))
			{
				temp = str[top];
				str[top] = str[seek];
				str[seek] = temp;
			}
	puts("display in order of ascii:");
	display_string(str, num);
}

void len_string(char *str[], int num)
{
	char *temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if ((strlen(str[top]) > strlen(str[seek])))
			{
				temp = str[top];
				str[top] = str[seek];
				str[seek] = temp;
			}
	puts("display in order of string's length.");
	display_string(str, num);
}

int len_word(char *str)
{
	int i;
	for (i = 0; i < strlen(str); i++)
		if (isspace(str[i]))
			break;
	return i;
}

void word_string(char *str[] , int num)
{
	char *temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (len_word(str[top]) > len_word(str[seek]))
			{
				temp = str[top];
				str[top] = str[seek];
				str[seek] = temp;
			}
	puts("display in order of first word's length.");
	display_string(str, num);
}
