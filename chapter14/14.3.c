/*
My Life as a Budgie
Mack Zackles
12.95
Thought and Unthought Rethought
Kindra Schlagmeyer
43.5
The Business of a Bee
Salome Deschamps
14.99
The CEO Power Diet
Buster Downsize
19.25
C++ Primer Plus
Stephen Prata
40.00
Under a Tofu Moon
Angus Bull
15.97
Coping with Coping
Dr. Rubin Thonkwacker
0.00
Delicate Frivolity
Neda McFey
29.99
Mrder Wore a Bikini
Mickey Splats
18.95
A History of Buvania. Volume 4
Prince Nikoli Buvan
50.00
Mastering Your Digital watch, 2nd Edition
Miklos Mysz
18.95
A Foregone Confusion
Phalty Reasoner
5.99
Outsourcing Government:Selection vs. Election
Ima Pundit
33.33
*/

#include <stdio.h>
#define MAXTITL 100
#define MAXAUTL 100
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void ststr(struct book *[], int);
void valstr(struct book *[], int);
void show(struct book *[], int);
void cleanup(void);
char *s_gets(char *, int);
void line1(void);
void line2(void);

int main(void)
{
	int index;
	int count = 0;
	struct book library[MAXBKS];
	struct book *p1[MAXBKS];
	struct book *p2[MAXBKS];

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets (library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		cleanup();
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	if (count > 0)
	{
		for (index = 0; index < count; index++)
		{
			p1[index] = &library[index];
			p2[index] = &library[index];
		}
	}
	else
	{
		printf("No books? Too bad.\n");
		return 0;
	}
	printf("The list of your books by the input sequence:\n");
	line1();
	show(p1, count);
	line2();
	printf("\nThe list of your books by title:\n");
	line1();
	ststr(p1, count);
	show(p1, count);
	line2();
	printf("\nThe list of your books by book value:\n");
	line1();
	valstr(p2, count);
	show(p2, count);
	line2();
	return 0;
}

char *s_gets(char *str, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void show(struct book *sp[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s by %s: $%.2f\n", sp[i]->title, sp[i]->author, sp[i]->value);
}

void valstr(struct book *sp[], int n)
{
	struct book *temp;
	int top, seek;

	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (sp[top]->value > sp[seek]->value)
			{
				temp = sp[top];
				sp[top] = sp[seek];
				sp[seek] = temp;
			}
}

void ststr(struct book *sp[], int n)
{

	struct book *temp;
	int top, seek;

	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (strcmp(sp[top]->title, sp[seek]->title) > 0)
			{
				temp = sp[top];
				sp[top] = sp[seek];
				sp[seek] = temp;
			}
}

void cleanup(void)
{
	while (getchar() != '\n');
}

void line1(void)
{
	int i = 0;
	int n = 35;

	printf("\n");
	for (i = 0; i < n; i++)
		putchar('#');
	printf("\n");
}

void line2(void)
{
	int i = 0;
	int n = 35;

	for (i = 0; i < n; i++)
		putchar('$');
	printf("\n");
}
