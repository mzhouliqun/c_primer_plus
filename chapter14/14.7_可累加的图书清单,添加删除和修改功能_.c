#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
#define DATAFILE "book.dat"
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int count = 0;
void read_file(struct book *, char *);
void show_menue(void);
void display(struct book *);
void change(struct book *);
void reduce(struct book *);
void add(struct book *);
void write_file(struct book *, char *);
char *s_gets(char *, int);
int main(void)
{
	struct book library[MAXBKS];
	char command[10];
	read_file(library, DATAFILE);
	show_menue();
	while (1)
	{
		s_gets(command, 2);
		switch(command[0])
		{
			case 'd': display(library); break;
			case 'c': change(library); break;
			case 'r': reduce(library); break;
			case 'a': add(library); break;
			default : write_file(library, DATAFILE); return 0;
		}
		printf("\nSelect: d/c/r/a/other:\n\n");
	}
	return 0;
}

void read_file(struct book *p, char *filename)
{
	FILE *pbooks;
	if ((pbooks = fopen(filename, "a+")) == NULL)
	{
		printf("Can not open file %s!\n", filename);
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(p + count, sizeof (struct book), 1, pbooks) == 1)
		count++;
	if (fclose(pbooks))
	{
		fprintf(stderr, "Close file failure!\n");
		exit(EXIT_FAILURE);
	}
	printf("Read %s successfully! There are %d books.\n", filename, count);
}

void show_menue(void)
{
	printf("Select the functions:\n");
	printf("\n(d) display all books\n");
	printf("(c) change a book\n");
	printf("(r) reduce a book\n");
	printf("(a) add books\n");
	printf("(other) save and quit\n\n");
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

void display(struct book *p)
{
	int i;
	if (count == 0)
		printf("\nThere is no book.\n");
	printf("\nBook list for %d books:\n\n", count);
	for (i = 0; i < count; i++)
		printf("%s by %s: $%.2f\n", p[i].title, p[i].author, p[i].value);
}

void change(struct book *p)
{
	int i;
	char title[MAXTITL];
	printf("Input the name of the book which you want to change:\n");
	s_gets(title, MAXTITL);
	for (i = 0; i < count; i++)
		if (strcmp(p[i].title, title) == 0)
		{
			printf("Please add new a book title.\n");
			s_gets(p[i].title, MAXTITL);
			printf("Now enter the author.\n");
			s_gets(p[i].author, MAXAUTL);
			printf("Now enter the value.\n");
			while (scanf("%f", &p[i].value) != 1)
			{
				while (getchar() != '\n')
					continue;
				fprintf(stderr, "Input error, try again!\n");
			}
			getchar();
			printf("The book has been changed!\n");
			return;
		}
	printf("Error! The book is not in the list.\n");
}

void reduce(struct book *p)
{
	int i;
	char title[MAXTITL];

	if (count == 0)
	{
		printf("Error! Book list is empty!\n");
		return;
	}
	printf("Input the name of the book which you want to reduce:\n");
	s_gets(title, MAXTITL);
	for (i = 0; i < count; i++)
		if (strcmp(p[i].title, title) == 0)
		{
			p[i] = p[count - 1];
			strcpy(p[count - 1].title, "");
			strcpy(p[count - 1].author, "");
			p[count - 1].value = 0;
			count--;
			printf("%s has been delete from book list\n", title);
			return;
		}
	printf("Error! %s is not in book list\n", title);
}

void add(struct book *p)
{
	if (count == MAXBKS)
	{
		fputs("Error, The file DATAFILE is full.", stderr);
		return;
	}
	printf("Please add new book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(p[count].title, MAXTITL) != NULL && p[count].title[0] != '\0')
	{
		printf("Now input the author.\n");
		s_gets(p[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		while (scanf("%f", &p[count++].value) != 1)
		{
			while (getchar() != '\n')
				continue;
			count--;
			fprintf(stderr, "Input error, try again!\n");
		}
		getchar();
		if (count < MAXBKS)
			printf("Input the next title.\n");
		else
			printf("The book list file is full.\n");
	}
}

void write_file(struct book *p, char *str)
{
	FILE *pbooks;
	pbooks = fopen(str, "w");
	pbooks = fopen(str, "r+");
	fwrite (p, sizeof(struct book), count, pbooks);
	if (fclose(pbooks))
	{
		fprintf(stderr, "Close file failure!\n");
		exit(EXIT_FAILURE);
	}
}
