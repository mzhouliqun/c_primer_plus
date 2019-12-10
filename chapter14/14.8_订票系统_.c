#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSEAT 12
#define SIZE 40
#define DATAFILE "data.info"

struct full_name {
	char first[SIZE];
	char last[SIZE];
};

struct ticket {
	int seatnum;
	int status;
	struct full_name name;
};

int count = 0;

void menue(void);
void read_file(struct ticket *, char *);
char *s_gets(char *, int);
void show_empty_num(struct ticket *);
void show_empty_list(struct ticket *);
void show_alphabetical_list(struct ticket *);
void assign(struct ticket *);
void delete(struct ticket *);
void write_file(struct ticket *, char *);

int main (void)
{
	struct ticket ticket_info[MAXSEAT];
	char command[10];
	int i;

	read_file(ticket_info, DATAFILE);
	if (count == 0)
	{
		printf("Datafile is empty, it will be initialized!\n");
		for (i = 0; i < MAXSEAT; i++)
		{
			ticket_info[i].seatnum = i + 1;
			ticket_info[i].status = 0;
			strcpy(ticket_info[i].name.first, "");
			strcpy(ticket_info[i].name.last, "");
		}
	}
	menue();
	while (1)
	{
		s_gets(command, 2);
		switch (command[0])
		{
			case 'a': show_empty_num(ticket_info); break;
			case 'b': show_empty_list(ticket_info); break;
			case 'c': show_alphabetical_list(ticket_info); break;
			case 'd': assign(ticket_info); break;
			case 'e': delete(ticket_info); break;
			case 'f': menue(); break;
			case 'g': return 0;
			default : write_file(ticket_info, DATAFILE); return 0;
		}
		printf("\nSelect: a/b/c/d/e/f/g/other:\n\n");
	}
	return 0;
}

void menue(void)
{
	printf("\nTo Choose a function, enter its letter label:\n\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Show menue\n");
	printf("g) Quit without save\n");
	printf("other) Quit and save\n\n");
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
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void read_file(struct ticket *p, char *filename)
{
	FILE *fp;
	int i;

	if ((fp = fopen(filename, "a+")) == NULL)
	{
		printf("Can not open file %s!\n", filename);
		exit(EXIT_FAILURE);
	}
	rewind (fp);
	while (count < MAXSEAT && fread(p + count, sizeof(struct ticket), 1, fp) == 1)
		count++;
	if (fclose(fp))
	{
		fprintf(stderr, "Close file failure!\n");
		exit(EXIT_FAILURE);
	}
	printf("Read %s successfully!\n", filename);
}

void write_file(struct ticket *p, char *str)
{
	FILE *fp;
	fp = fopen(str, "w");
	fwrite(p, sizeof(struct ticket), MAXSEAT, fp);
	fclose(fp);
}

void show_empty_num(struct ticket *p)
{
	int i = 0;
	int num = 0;

	for (i = 0; i < MAXSEAT; i++)
		if (p[i].status == 0)
			num++;
	printf("\nThe number of empty seat is %d\n", num);
}

void show_empty_list(struct ticket *p)
{
	int i = 0;
	int num = 0;
	int value = 0;

	printf("\n");
	for (i = 0; i < MAXSEAT; i++)
		if (p[i].status == 0)
		{
			printf("Seat %d\t available\n", p[i].seatnum);
			value = 1;
		}
	if (value == 0)
		printf("All seats have been assigned\n");
}

void show_alphabetical_list(struct ticket *p)
{
	int i = 0;
	int value = 0;

	printf("\n");
	for (i = 0; i < MAXSEAT; i++)
	{
		if (p[i].status == 1)
		{
			printf("Seat %d: %s\t%s\n", p[i].seatnum, p[i].name.first, p[i].name.last);
			value = 1;
		}
	}
	if (value == 0)
		printf("No seats were assigned\n");
}

void assign(struct ticket *p)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int empty[MAXSEAT] = {0};
	int assigned[MAXSEAT] = {0};

	for (i = 0; i < MAXSEAT; i++)
		if (p[i].status == 1)
		{
			assigned[j] = p[i].seatnum;
			j++;
		}
	printf("\n");
	if (j != MAXSEAT)
	{
		for (i = 0; i < MAXSEAT; i++)
			if (p[i].status == 0)
				printf("Seat %d\t available\n", p[i].seatnum);
	}
	else
	{
		printf("All seats have been assigned\n");
		return;
	}
	printf("\nPlease select seat number!\n\n");
	while (scanf("%d", &temp) != 1 || temp < 0 || temp > MAXSEAT)
	{
		fprintf(stderr, "Input error! Try again!\n");
		while (getchar() != '\n');
		return;
	}
	getchar();
	printf("\nThe seat number you chose is %d\n", temp);
	if (p[temp - 1].status == 1)
	{
		printf("\nError! Seat %d has been assigned!\n", temp);
		return;
	}
	printf("\nPlease input your first name:\n\n");
	s_gets(p[temp - 1].name.first, SIZE);
	printf("\nPlease input your lase name:\n\n");
	s_gets(p[temp - 1].name.last, SIZE);
	p[temp - 1].status = 1;
}

void delete(struct ticket *p)
{
	int i = 0;
	int temp = 0;
	int assigned = 0;

	show_alphabetical_list(p);
	for (i = 0; i < MAXSEAT; i++)
	{
		if (p[i].status == 1)
		{
			assigned = 1;
			break;
		}
	}
	if (assigned == 0)
	{
		printf("\nAll the seats ware not assigned\n");
		return;
	}
	printf("\nPlease input your seat number which you want to delete:\n\n");
	while (scanf("%d", &temp) != 1 || temp < 1 || temp > 13)
	{
		fprintf(stderr, "Input error! Try again!\n");
		while (getchar() != '\n');
		return;
	}
	getchar();
	if (p[temp - 1].status == 0)
	{
		printf("Error! Seat %d is not assigned.\n", temp - 1);
		return;
	}
	else
	{
		p[temp - 1].status = 0;
		strcpy(p[temp - 1].name.first, "");
		strcpy(p[temp - 1].name.last, "");
		printf("\nOperate successfully\n");
	}
}
