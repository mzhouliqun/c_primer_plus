#include <stdio.h>
#include <unistd.h>
#define OFF 0
#define ON 1
#define LEFT 0
#define CENTER 1
#define RIGHT 2
struct text_settings {
	unsigned int font_id		: 8;
	unsigned int font_size		: 7;
	unsigned int				: 1;
	unsigned int alignment		: 2;
	unsigned int tog_bold		: 1;
	unsigned int tog_italic		: 1;
	unsigned int tog_underline	: 1;
	unsigned int				: 3;
};
const char *alg[3] = {"left", "center", "right"};
const char *toggle[2] = {"off", "on"};
void show_menu(void);
void show_status(struct text_settings *);
char *s_gets(char *, int);
void change_font(struct text_settings *);
void change_size(struct text_settings *);
void change_alignment(struct text_settings *);
void toggle_bold(struct text_settings *);
void toggle_italic(struct text_settings *);
void toggle_underline(struct text_settings *);
int main(void)
{
	struct text_settings settings = {1, 12, LEFT, OFF, OFF, OFF};
	char options[10];

	show_status(&settings);
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
		show_status(&settings);
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

void show_status(struct text_settings *p)
{
	printf("\nID \tSIZE \tALIGNMENT \tB \tI \tU\n");
	printf("%d \t%d \t%s \t\t%s \t%s \t%s\n", p->font_id, p->font_size, alg[p->alignment], toggle[p->tog_bold], toggle[p->tog_italic], toggle[p->tog_underline]);
}

char *s_gets(char *str, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(str, n, stdin);
	if(ret_val)
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

void change_font(struct text_settings *p)
{
	int id;

	printf("\nEnter font id (0-255): ");
	while (scanf("%d", &id) != 1 || id < 0 || id > 255)
	{
		getchar();
		printf("\nInput error! Please try again!\n");
	}
	getchar();
	p->font_id = id & 255;
}

void change_size(struct text_settings *p)
{
	int size;

	printf("\nEnter font size (0-127): ");
	while (scanf("%d", &size) != 1 || size < 0 || size > 127)
	{
		getchar();
		printf("\nInput error! Please try again!\n");
	}
	getchar();
	p->font_size = size & 127;
}

void change_alignment(struct text_settings *p)
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
	switch(ch)
	{
		case 'l': p->alignment = LEFT; break;
		case 'c': p->alignment = CENTER; break;
		case 'r': p->alignment = RIGHT; break;
	}
}

void toggle_bold(struct text_settings *p)
{
	p->tog_bold = ~p->tog_bold;
}

void toggle_italic(
(struct text_settings *p)
{
	p->tog_italic = ~p->tog_italic;
}

void toggle_underline(struct text_settings *p)
{
	p->tog_underline = ~p->tog_underline;
}
