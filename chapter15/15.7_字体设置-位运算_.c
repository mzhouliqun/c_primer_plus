#include <stdio.h>
#include <unistd.h>
#define ID_MASK 0xff
#define SIZE_MASK 0x7f00
#define ALIGNMENT_MASK 0x30000
#define BOLD_MASK 0x40000
#define ITALIC_MASK 0x80000
#define UNDERLINE_MASK 0x100000
/*struct text_settings {
	unsigned int font_id		: 8;
	unsigned int font_size		: 7;
	unsigned int				: 1;
	unsigned int alignment		: 2;
	unsigned int tog_bold		: 1;
	unsigned int tog_italic		: 1;
	unsigned int tog_underline	: 1;
	unsigned int				: 3;
};*/
const char *alg[3] = {"left", "center", "right"};
const char *toggle[2] = {"off", "on"};
void show_menu(void);
void show_status(unsigned int);
char *s_gets(char *, int);
void change_font(unsigned int *);
void change_size(unsigned int *);
void change_alignment(unsigned int *);
void toggle_bold(unsigned int *);
void toggle_italic(unsigned int *);
void toggle_underline(unsigned int *);
int main(void)
{
	unsigned int settings = 0xc01;
	char options[10];

	show_statu (settings);
	show_menu();
	for (;;)
	{
		s_gets(options, 2);
		switch (options[0])
		{
			case 'f': change_font(&settings); break;
			case 's': change_size(&settings); break;
			case 'a': change_alignment(&settings); break;
			case 'b': toggle_bold(&settings); break;
			case 'i': toggle_italic(&settings); break;
			case 'u': toggle_underline(&settings); break;
			case 'q': printf("Bye!\n"); return 0;
			default : printf("Input error! Please select: f/s/a/b/i/u/q\n\n"); sleep(1);
		}
		show_status(settings);
		show_menu();
	}
	return 0;
}

void show_menu(void)
{
	printf("\nf) change font.\n");
	printf("s) change size.\n");
	printf("a) change alignment.\n");
	printf("b) toggle bold.\n");
	printf("i) toggle italic.\n");
	printf("u) toggle underline.\n");
	printf("q) quit.\n\n");
}

void show_status(unsigned int setnum)
{
	printf("\nID \tSIZE \tALIGNMENT \tB \tI \tU\n");
	printf("%d \t%d \t%s \t\t%s \t%s \t%s\n", setnum  & ID_MASK, (setnum & SIZE_MASK)>>8, alg[(setnum & ALIGNMENT_MASK)>>16], toggle[(setnum & BOLD_MASK)>>18], toggle[(setnum & ITALIC_MASK)>>19], toggle[(setnum & UNDERLINE_MASK)>>20]);
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
			while (getchar() != '\n');
	}
	return ret_val;
}

void change_font(unsigned int *ps)
{
	int id;

	printf("\nEnter font id (0-255): ");
	while (scanf("%d", &id) != 1 || id < 0 || id > 255)
	{
		getchar();
		printf("\nInput error! Please try again!\n");
	}
	getchar();
	*ps &= ~ID_MASK;
	*ps += id;
}

void change_size(unsigned int *ps)
{
	int size;

	printf("\nEnter font size (0-127): ");
	while (scanf("%d", &size) != 1 || size < 0 || size > 127)
	{
		getchar();
		printf("\nInput error! Please try again!\n");
	}
	getchar();
	*ps = (*ps & ~SIZE_MASK) + (size<<8);
}

void change_alignment(unsigned int *ps)
{
	char ch;

	printf("\nSelect alignment:\n\n");
	printf("l) left.\n");
	printf("c) center.\n");
	printf("r) right.\n\n");

	while (1)
	{
		while (scanf("%c", &ch) != 1 || ch == '\n')
		{
			if (ch == '\n')
				continue;
			else
				printf("Input error! Please try again.\n");
		}
		while (getchar() != '\n');
		if (ch != 'l' && ch != 'c' && ch != 'r')
		{
			printf("Input error! Please select: l/c/r\n\n");
			continue;
		}
		break;
	}
	switch (ch)
	{
		case 'l': *ps &= ~ALIGNMENT_MASK; break;
		case 'c': *ps &= ~ALIGNMENT_MASK; *ps += (1<<16); break;
		case 'r': *ps = (*ps & ~ALIGNMENT_MASK) + (2<<16); break;
	}
}

void toggle_bold(unsigned int *ps)
{
	*ps ^= BOLD_MASK;
}

void toggle_italic(unsigned int *ps)
{
	*ps ^= ITALIC_MASK;
}

void toggle_underline(unsigned int *ps)
{
	*ps ^= UNDERLINE_MASK;
}
