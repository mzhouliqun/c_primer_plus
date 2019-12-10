#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 100
#define LEN 40
struct names {
	char first[LEN];
	char last[LEN];
};
struct names staff[NUM] = {
	{"Tristan", "Zhou"},
	{"Harry", "Poter"},
	{"boguang", "tian"},
	{"botong", "zhou"},
	{"yingying", "ren"},
	{"cuixue", "ximen"},
	{"huchong", "ling"},
	{"woxing", "ren"},
	{"xiaofeng", "lu"},
	{"caidie", "lan"},
	{"jing", "guo"},
	{"zhiruo", "zhou"},
	{"wuji", "zhang"},
	{"qiubai", "dugu"},
	{"min", "zhao"},
	{"feng", "qiao"},
	{"yu", "duan"},
	{"tonglao", "tianshan"},
	{"laoyao", "heishan"},
	{"caichen", "ning"},
	{"teman", "ao"},
};
int comp(const void *, const void *);
void show_list(struct names *);
int main(void)
{
	show_list(staff);
	printf("\n################################\n\n");
	qsort(staff, NUM, sizeof(struct names), comp);
	show_list(staff);
	return 0;
}

int comp(const void *p1, const void *p2)
{
	const struct names *ps1 = p1;
	const struct names *ps2 = p2;
	int res;

	res = strcmp(ps1->last, ps2->last);
	if (res != 0)
		return res;
	else
		return strcmp(ps1->first, ps2->first);
}

void show_list(struct names *p)
{
	int i;

	for (i = 0; i < NUM; i++)
	{
		if ((strlen(p[i].first) != 0) || (strlen(p[i].last) != 0))
		{
			if (strlen(p[i].first) == 0)
				printf("%s", "NULL");
			else
				printf("%s", p[i].first);
			printf("\t\t");
			if (strlen(p[i].last) == 0)
				printf("%s", "NULL");
			else
				printf("%s", p[i].last);
			printf("\n");
		}
	}
}
