#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(List *list);
void uppercase(char *str);
int ListItemCount(Node *root);
char *s_gets(char *str, int n);
bool checkvoid(char *str);

int main(void)
{
	Tree pets;
	char choice;
	int count = 0;
	int temp = 0;

	InitializeTree(&pets);
	while((choice = menu()) != 'q')
	{
		switch (choice)
		{
			case 'a': addpet(&pets);
				break;
			case 'l': showpets(&pets);
				break;
			case 'f': findpet(&pets);
				break;
			case 'n':
				count = ListItemCount(pets.root);
				count -= temp;
				temp += count;
				printf("\n%d pets in club\n", count);
				break;
			case 'd': droppet(&pets);
				break;
			default: printf("Switching error!\n");
		}
	}
	DeleteAll(&pets);
	printf("\nBye.\n");
	return 0;
}

char menu(void)
{
	int ch;

	printf("\nNerfville pet Club Membership Program\n");
	printf("Enter the letter corresponding to your choice:\n\n");
	printf("a) add a pet			l) show list of pets\n");
	printf("n) number of pets		f) find pets\n");
	printf("d) delete a pet			q) quit\n\n");
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
		printf("\nNo room in the club!\n");
	else
	{
		printf("\nPlease enter name of pet:\n\n");
		while (checkvoid(s_gets(temp.petname, MAX_STR_LEN)));
		printf("\nPlease enter pet kind:\n\n");
		while (checkvoid(s_gets(temp.petkind, MAX_STR_LEN)));
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddTreeItem(&temp, pt);
	}
}

void showpets(const Tree *pt)
{
	if (TreeIsEmpty(pt))
		printf("No entries!\n\n");
	else
		Traverse(pt, printitem);
}

void printitem(List *pl)
{
	putchar('\n');
	while (pl != NULL)
	{
		printf("pet: %-19s        kind: %-19s\n", pl->item.petname, pl->item.petkind);
		pl = pl->next;
	}
}

void findpet(const Tree *pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		printf("No entries!\n\n");
		return;
	}
	printf("\nPlease enter name of pet you wish to find:\n\n");
	while (checkvoid(s_gets(temp.petname, MAX_STR_LEN)));
	printf("\nPlease enter pet kind:\n\n");
	while (checkvoid(s_gets(temp.petkind, MAX_STR_LEN)));
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

	if (TreeIsEmpty(pt))
	{
		printf("\nNo entries!\n");
		return;
	}
	printf("\nPlease enter name of pet you wish to delete:\n\n");
	while (checkvoid(s_gets(temp.petname, MAX_STR_LEN)));
	printf("\nPlease enter pet kind:\n\n");
	while (checkvoid(s_gets(temp.petkind, MAX_STR_LEN)));
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

int ListItemCount(Node *root)
{
	static int count = 0;

	if (root != NULL)
	{
		ListItemCount(root->left);
		count += root->list_size;
		ListItemCount(root->right);
	}
	return count;
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

bool checkvoid(char *str)
{
	return *str == '\0';
}
