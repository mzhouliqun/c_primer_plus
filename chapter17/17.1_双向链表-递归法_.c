#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film *next;
};

struct film *head = NULL;
struct film *current;

char *s_gets(char *, int);
void positive_seq(struct film *);
void reverse_seq(struct film *);
void show(struct film *);

int main(void)
{
	struct film *prev;
	char input[TSIZE];
	char ch;

	puts("Enter first movie title: ");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}
	if (head == NULL)
		printf("No data entered.");
	else
	{
		printf("Positive sequence display or reverse sequence display? (input p or r):\n\n");
		while (ch = getchar(), &ch != NULL && ch != '\0')
		{
			if (ch == 'p')
				positive_seq(current);
			else if (ch == 'r')
				reverse_seq(head);
			else
			{
				printf("Input error! Positive sequence display or reverse sequence display? (input p or r):\n");
				continue;
			}
			break;
		}
	}
	current = head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	printf("Bye!\n");
	return 0;
}

char *s_gets(char *str, int n)
{
	int i = 0;
	char *ret_val;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}

void positive_seq(struct film *sp)
{
	sp = head;
	
	printf("\nHere is the movie list:\n");
	while (sp != NULL)
	{
		printf("Movie: %s Rating: %d\n", sp->title, sp->rating);
		sp = sp->next;
	}
}

void reverse_seq(struct film *sp)
{
	printf("\nHere is the movie list:\n");
	show(sp);
}

void show(struct film *sp)
{
	if(sp->next != NULL)
		show(sp->next);
	printf("Movie: %s Rating: %d\n", sp->title, sp->rating);
}
