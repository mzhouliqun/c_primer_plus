/*
0 boguang tian 5 2 1 1
1 botong zhou 4 2 1 1
2 yingying ren 3 1 1 1
3 cuixue ximen 6 2 1 1
4 huchong ling 5 3 1 1
5 woxing ren 2 0 1 1
6 qiubai dugu 0 0 0 0
7 xiaofeng lu 5 3 1 1
8 caidie lan 5 2 1 2
9 jing guo 5 2 2 1
17 caichen ning 3 2 1 1
10 zhiruo zhou 3 0 1 1
11 wuji zhang 5 2 0 1
6 qiubai dugu  3 3 1 1
12 min zhao 7 4 1 1
13 feng qiao 8 6 1 1
14 yu duan 10 2 5 7
15 tonglao tianshan  3 1 1 1
16 laoyao heishan 5 2 0 1
17 caichen ning 6 2 1 1
18 teman ao 1 1 1 1
6 qiubai dugu 2 2 0 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENTH 20
#define SIZE 19
struct fullname {
	char first[LENTH];
	char last[LENTH];
};
struct player_info {
	struct fullname name;
	int appearances;
	int hit;
	int base;
	int points;
	float hit_rate;
};
void showplayer(struct player_info *, int);
void showteam(struct player_info *, int);
int main(int argc, char *argv[])
{
	int i = 0;
	FILE *fp;
	struct player_info temp;
	struct player_info player[SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not opent file %s!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	memset(player, 0, sizeof(player));
	while (fscanf(fp, "%d%s%s%d%d%d%d", &i, &temp.name.first, &temp.name.last, &temp.appearances, &temp.hit, &temp.base, &temp.points) == 7)
	{
		if (strcmp(player[i].name.first, temp.name.first) != 0)
			strcpy(player[i].name.first, temp.name.first);
		if (strcmp(player[i].name.last, temp.name.last) != 0)
			strcpy(player[i].name.last, temp.name.last);
		player[i].appearances += temp.appearances;
		player[i].hit += temp.hit;
		player[i].base += temp.base;
		player[i].points += temp.points;
	}
	for (i = 0; i < 19; i++)
		player[i].hit_rate = (float) player[i].hit / (float) player[i].appearances;
	showplayer(player , SIZE);
	showteam(player, SIZE);
	if (fclose(fp))
	{
		fprintf(stderr, "Close file %s failure!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}

void showplayer(struct player_info *p, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
		printf("%s %s: %d %d %d %d %.2f\n", p[i].name.first, p[i].name.last, p[i].appearances, p[i].hit, p[i].base, p[i].points, p[i].hit_rate);
}

void showteam(struct player_info *p, int n)
{
	int i;
	struct player_info team;
	memset (&team, 0, sizeof(team));
	for (i = 0; i < n; i++)
	{
		team.appearances += p[i].appearances;
		team.hit += p[i].hit;
		team.base += p[i].base;
		team.points += p[i].points;
	}
	team.hit_rate = (float) team.hit / (float) team.appearances;
	printf("Team comprehensive statistics:\n");
	printf("team appearances: %d\n", team.appearances);
	printf("team hit: %d\n", team.hit);
	printf("team base: %d\n", team.base);
	printf("team points: %d\n", team.points);
	printf("team hit_rate: %.2f\n", team.hit_rate);
}
