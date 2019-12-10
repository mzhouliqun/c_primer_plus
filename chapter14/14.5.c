#include <stdio.h>
#define LENTH 40
#define SIZE 3
#define CSIZE 4

struct fullname {
	char first[LENTH];
	char last[LENTH];
};

struct student {
	struct fullname name;
	float grade[SIZE];
	float average;
};

void get_score(struct student *, int);
void get_average(struct student *, int);
void show_strinfo(struct student *, int);
void show_subject_average(struct student *, int, int);

int main(void)
{
	struct student group1[CSIZE] = {
		{{"Leonardo", "DiCaprio"}},
		{{"Brad", "Pitt"}},
		{{"John", "Depp"}},
		{{"Jennifer", "Connelly"}}
	};
	struct student *stp;
	stp = group1;
	get_score(stp, CSIZE);
	get_average(stp, CSIZE);
	show_strinfo(stp, CSIZE);
	show_subject_average(stp, SIZE, CSIZE);
	return 0;
}

void get_score(struct student *p, int n)
{
	int i;

	printf("Please enter the three subjects scores of every student according to the system prompts:\n");
	for (i = 0; i < n; i++)
	{
		printf("the three subjects scores of  %s %s:\n", p[i].name.first, p[i].name.last);
		while (scanf("%f%f%f", &p[i].grade[0], &p[i].grade[1], &p[i].grade[2]) != 3)
		{
			printf("Input error! Try again~\n");
			while (getchar() != '\n');
			continue;
		}
	}
}

void get_average(struct student *p, int n)
{
	int i;
	int j;
	float tot;

	for (i = 0; i < n; i++)
	{
		for (j = 0, tot = 0; j < SIZE; j++)
			tot += p[i].grade[j];
		p[i].average = tot / SIZE;
	}
}

void show_strinfo(struct student *p, int n)
{
	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		printf("\n");
		printf("%s %s:\n", p[i].name.first, p[i].name.last);
		for (j = 0; j < SIZE; j++)
			printf("subject%d: %.2f\n", j + 1, p[i].grade[j]);
		printf("average: %.2f\n", p[i].average);
		printf("\n");
	}
}

void show_subject_average(struct student *p, int n1, int n2)
{
	int i;
	int j;
	float tot;
	float subjectave[n1];

	for (i = 0; i < n1; i++)
	{
		for (j = 0, tot = 0; j < n2; j++)
			tot += p[j].grade[i];
		subjectave[i] = tot / n2;
		printf("The average of subject%d is %.2f\n", i + 1, subjectave[i]);
	}
}
