#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

void menu(void);
int get_ch(char *str);
void print_item(Item item);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [file_name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fp;
	Tree tree;
	Item word = {{'\0'}, 1};
	char ch;

	InitializeTree(&tree);
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Open file %s failure!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		int i = 0;
		while (isalpha(ch))
		{
			word.word[i++] = ch;
			ch = getc(fp);
		}
		if (i > 0)
		{
			word.word[i++] = '\0';
			AddItem(&word, &tree);
		}
	}
	putchar('\n');
	fclose(fp);
	menu();
	while ((ch = get_ch("abq")) != 'q')
	{
		if (ch == 'a')
		{
			puts("\nWord appeared\t\tCounts occurrences of each word");
			Traverse(&tree, print_item);
		}
		if (ch == 'b')
		{
			puts("\nEnter the word you are looking for\n");
			scanf("%s", word.word);
			while (getchar() != '\n');
			if (InItem(&word, &tree))
				printf("\n%s appears %d time(s) in file %s\n", word.word, InItem(&word, &tree)->item.word_count, argv[1]);
			else
				printf("\nword \"%s\" was not found in file %s\n", word.word, argv[1]);
		}
		printf("\n");
		menu();
	}
}

void menu(void)
{
	puts("Please enter options:\n");
	puts("a) List all the words and the counts of each word appeared.");
	puts("b) Enter a word and the program displays the counts of each word appeared in the file.");
	puts("q) Quit program.\n");
}

int get_ch(char *str)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n');
	while (strchr(str, ch) == NULL)
	{
		printf("\nPlease enter an a, b or q:\n\n");
		ch = getchar();
		while (getchar() != '\n');
	}
	return ch;
}

void print_item(Item item)
{
	printf("%15s\t\t\t%14d\n", item.word, item.word_count);
}
