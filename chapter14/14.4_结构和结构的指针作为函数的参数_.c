#include <stdio.h>
#include <string.h>
#define LENTH 40
#define NUM 5
struct name {
	char first[LENTH];
	char middle[LENTH];
	char last[LENTH];
};

struct ssml {
	int ssn;
	struct name ssname;
};

struct ssml actor[NUM] = {
	{302039823, {"Leonardo", "Wilelm", "DiCaprio"}},
	{302039824, {"Brad", "", "Pitt"}},
	{302039825, {"John", "Christopher", "Depp"}},
	{302039825, {"Jennifer", "Lynn", "Connelly"}},
	{302039827, {"Tristan", "Max", "Zhou"}}
};

void showa(struct ssml *, int);
void showb(struct ssml);

int main(void)
{
	int i;

	printf("\nMode a:\n\n");
	showa(actor, NUM);
	printf("\nMode b:\n\n");
	for (i = 0; i < NUM; i++)
		showb(actor[i]);
	return 0;
}

void showa(struct ssml *p, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
	
		if (strlen(p[i].ssname.middle))
			printf("%s, %s %c. - %d\n", p[i].ssname.first, p[i].ssname.last, p[i].ssname.middle[0], p[i].ssn);
		else
			printf("%s, %s    - %d\n", p[i].ssname.first, p[i].ssname.last, p[i].ssn);
	}
}

void showb(struct ssml stru)
{
	if (strlen(stru.ssname.middle))
		printf("%s, %s %c. - %d\n", stru.ssname.first, stru.ssname.last, stru.ssname.middle[0], stru.ssn);
	else
		printf("%s, %s    - %d\n", stru.ssname.first, stru.ssname.last, stru.ssn);
}

