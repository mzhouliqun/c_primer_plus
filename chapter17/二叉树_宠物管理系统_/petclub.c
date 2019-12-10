#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#define MAXLEN 20

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char * str);
char *s_gets(char *, int);

int main(void)
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
			case 'a': addpet(&pets); break;
			case 'l': showpets(&pets); break;
			case 'f': findpet(&pets); break;
			case 'n': printf("\n%d pets in club\n", TreeItemCount(&pets)); break;
			case 'd': droppet(&pets); break;
			default : printf("\nSwitching error\n\n");
		}
	}
	DeleteAll(&pets);
	printf("\nBye.\n");
	return 0;
}

char menu(void)
{
	int ch;

	printf("\nNerfville Pet Club Membership Program\n");
	printf("Enter the letter corresponding to your choice:\n\n");
	printf("a) add a pet                l) show list of pets\n");
	printf("n) number of pets           f) find pets\n");
	printf("d) delete a pet             q) quit\n\n");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("alrfndq", ch) == NULL)
			printf("\nPlease enter an a, l, f, n, d, or q:\n\n");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';
	return ch;
}

void addpet(Tree *pt)
{
	Item temp;

	if (TreeIsFull(pt))
		printf("\nNo root in the club!\n");
	else
	{
		printf("\nPlease enter name of pet:\n\n");
		s_gets(temp.petname, MAXLEN);
		printf("\nPlease enter pet kind:\n\n");
		s_gets(temp.petkind, MAXLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp, pt);
	}
}

void showpets(const Tree *pt)
{
	if (TreeIsEmpty(pt))
		printf("\nNO entries!\n");
	else
	{
		printf("\n");
		Traverse(pt, printitem);
	}
}

void printitem(Item item)
{
	printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		printf("\nNo entries!\n");
		return;
	}
	printf("\nPlease enter name of pet you wish to find:\n\n");
	s_gets(temp.petname, MAXLEN);
	printf("\nPlease enter pet kind:\n\n");
	s_gets(temp.petkind, MAXLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("\n%s the %s ", temp.petname, temp.petkind);
	if (InTree(&temp, pt))
		printf("is a member.\n");
	else
		printf("is not a member.\n");
}

void droppet(Tree *pt)
{
	Item temp;

	if(TreeIsEmpty(pt))
	{
		printf("\nNo entries!\n");
		return;
	}

	printf("\nPlease enter name of pet you wish to delete:\n\n");
	s_gets(temp.petname, MAXLEN);
	printf("\nPlease enter pet kind:\n\n");
	s_gets(temp.petkind, MAXLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("\n%s the %s ", temp.petname, temp.petkind);
	if (DeleteItem(&temp, pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member.\n");
}

void uppercase(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

char *s_gets(char *str, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(str, n, stdin);
	if (ret_val != NULL)
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
