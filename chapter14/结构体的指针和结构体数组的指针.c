#include <stdio.h>
struct book {
	char title[40];
	char author[40];
	float value;
};

struct book library[100] = {
	{"a", "b", 1.1}
};

int main(void)
{
	struct book *fpr;
	fpr = &library[0];

	struct book(*spr)[100];
	spr = &library;

	struct book *apr[100];
	apr[0] = &library[0];

	printf("%f\n", library->value);
	printf("%f\n", (*library).value);
	printf("%f\n", library[0].value);
	printf("%f\n", fpr->value);
	printf ("%f\n", (*fpr).value);
	printf("%f\n", fpr[0].value);
	printf("%f\n", spr[0]->value);
	printf("%f\n", (*spr)->value);
	printf("%f\n", spr[0][0].value);
	printf("%f\n", apr[0]->value);
	printf("%f\n", (*apr)->value);
	printf("%f\n", apr[0][0].value);
	return 0;
}
