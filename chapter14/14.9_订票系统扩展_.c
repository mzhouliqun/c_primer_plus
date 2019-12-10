#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSEAT 12
#define LENGTH 40

struct flight_info {
	int flight_num;
	int seat_num;
	_Bool own;
	_Bool confirm;
	char first[LENGTH];
	char last[LENGTH];
};

int getflt(void);
char getchoice(int);
void show_num(struct flight_info *);
void show_list(struct flight_info *);
void show_alphabetical(struct flight_info *);
void assign(struct flight_info *);
void confirm(struct flight_info *);
void delete(struct flight_info *);
char *s_gets(char *, int);

int main(void)
{
	struct flight_info flight_tmp[MAXSEAT] = {
		{.seat_num = 1, .own = false, .confirm = false},
		{.seat_num = 2, .own = false, .confirm = false},
		{.seat_num = 3, .own = false, .confirm = false},
		{.seat_num = 4, .own = false, .confirm = false},
		{.seat_num = 5, .own = false, .confirm = false},
		{.seat_num = 6, .own = false, .confirm = false},
		{.seat_num = 7, .own = false, .confirm = false},
		{.seat_num = 8, .own = false, .confirm = false},
		{.seat_num = 9, .own = false, .confirm = false},
		{.seat_num = 10, .own = false, .confirm = false},
		{.seat_num = 11, .own = false, .confirm = false},
		{.seat_num = 12, .own = false, .confirm = false}
	};
	struct flight_info flight[MAXSEAT];
	int flt;
	char ch;
	FILE *fp;
	char file[LENGTH];
	int size = sizeof(struct flight_info);
	int count = 0;

	while ((flt = getflt()) != 0)
	{
		for (count = 0; count < MAXSEAT; count++)
			flight[count] = flight_tmp[count];
		switch (flt)
		{
			case 102:
				for (count = 0; count < MAXSEAT; count++)
					flight[count].flight_num = 102;
				strcpy(file, "FLIGHT_102");
				break;
			case 311:
				for (count = 0; count < MAXSEAT; count++)
					flight[count].flight_num = 311;
				strcpy(file, "FLIGHT_311");
				break;
			case 444:
				for (count = 0; count < MAXSEAT; count++)
					flight[count].flight_num = 444;
				strcpy(file, "FLIGHT_444");
				break;
			case 519:
				for (count = 0; count < MAXSEAT; count++)
					flight[count].flight_num = 519;
				strcpy(file, "FLIGHT_519");
				break;
		}
		if ((fp = fopen(file, "r+")) == NULL)
		{
			printf("\nCan't open file, create one!\n");
			fp = fopen(file, "a+");
		}
		rewind(fp);
		count = 0;
		while (count < MAXSEAT)
			fread(&flight[count++], size, 1, fp);
		if (fclose(fp))
		{
			fprintf(stderr, "Close file failure!\n");
			exit(EXIT_FAILURE);
		}
		while ((ch = getchoice(flt)) != 'q')
		{
			switch (ch)
			{
				case 'a': show_num(flight); break;
				case 'b': show_list(flight); break;
				case 'c': show_alphabetical(flight); break;
				case 'd': assign(flight); break;
				case 'e': confirm(flight); break;
				case 'f': delete(flight); break;
			}
		}
		if ((fp = fopen(file, "w")) == NULL)
		{
			fprintf(stderr, "Can't open file\n");
			exit(EXIT_FAILURE);
		}
		if (fwrite(flight, MAXSEAT * size, 1, fp))
			printf("\nSaved!\n\n");
		else
		{
			fprintf(stderr, "\nSave failed!\n");
			exit(EXIT_FAILURE);
		}
		if (fclose(fp))
		{
			fprintf(stderr, "Close file failure!\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("Bye.\n");
	return 0;
}

int getflt(void)
{
	int num;

	do
	{
		printf("Please input flight number. (0 to quit):\n");
		printf("\n102\n311\n444\n519\n\n");
		scanf("%d", &num);
		while(getchar() != '\n');
	} while (num != 102 && num != 311 && num != 444 && num != 519 && num != 0 && printf("\nWrong choice, try again!\n\n"));
	return num;
}

char getchoice(int fn)
{
	char ch;

	do
	{
		printf("\nFlight %d:\n", fn);
		printf("To choose a function, enther its letter label:\n");
		printf("a) Show number of empty seats\n");
		printf("b) Show list of empty seats\n");
		printf("c) Show alphabetical list of seats\n");
		printf("d) Assign a customer to a seat assignment\n");
		printf("e) Confirm the a seat assignment\n");
		printf("f) Delete a seat assignment\n");
		printf("q) Back\n\n");
		scanf("%c", &ch);
		while (getchar() != '\n');
	} while (!strchr("abcdefq", ch) && printf("\nInput error! Try again!\n"));
	return ch;
}

void show_num(struct flight_info *flight)
{
	int m;
	int n;

	for (n = 0, m = 0; n < MAXSEAT; n++)
		if (!flight[n].own)
			m++;
	printf("\n%d empty seats\n", m);
}

void show_list(struct flight_info *flight)
{
	int n;

	printf("\nEmpty seats:\n\n");
	for (n = 0; n < MAXSEAT; n++)
		if (!flight[n].own)
			printf ("Seat %d empty.\n", flight[n].seat_num);

}

void show_alphabetical(struct flight_info *flight)
{
	int n;
	char *temp;

	printf("\n");
	for (n = 0; n < MAXSEAT; n++)
	{
		if (flight[n].own)
		{
			printf("FLIGHT: %d\tseat number: %d\tname: %s\t%s\t", flight[n].flight_num, flight[n].seat_num, flight[n].first, flight[n].last);
			if (!flight[n].confirm)
				printf("\tunconfirmed\n");
			else
				printf("\tconfirmed\n");
		}
	}
}

void assign(struct flight_info *flight)
{
	int n = 1;

	show_list(flight);
	printf("\nWhich seat do you want to assign (0 to back):\n\n");
	while (scanf("%d", &n) && n > 0 && n <= MAXSEAT)
	{
		while (getchar() != '\n');
		if (!flight[--n].own)
		{
			printf("\nInput firstname:\n\n");
			s_gets(flight[n].first, LENGTH);
			printf("\nInput lastname:\n\n");
			s_gets(flight[n].last, LENGTH);
			flight[n].own = true;
		}
		else
			printf("\nIt is owned, try again!\n");
		printf("\nWhich seat do you want to assign (0 to back):\n\n");
	}
	while (getchar() != '\n');
}

void confirm(struct flight_info *flight)
{
	int n;
	printf("\nUnconfirmed seat number:\n");
	for (n = 0; n < MAXSEAT; n++)
		if (flight[n].own && !flight[n].confirm)
			printf("FLIGHT: %d\tseat number: %d\tname: %s\t%s\n", flight[n].flight_num, flight[n].seat_num, flight[n].first, flight[n].last);
	printf("\nWhich seat do you want to confirm (0 to back):\n\n");
	while (scanf("%d", &n) && n > 0 && n <= MAXSEAT)
	{
		while (getchar() != '\n');
		if (flight[--n].own && !flight[n].confirm)
			flight[n].confirm = true;
		else
			printf("It is not owned or it had confirmed, try again!\n");
		printf("\nWhich seat do you want to confirm (0 to back):\n\n");
	}
	while (getchar() != '\n');
}

void delete(struct flight_info *flight)
{
	int n;

	printf("\nOwned seats number:\n");
	for (n = 0; n < MAXSEAT; n++)
		if (flight[n].own)
			printf("FLIGHT: %d\tseat number: %d\t name: %s\t%s\n", flight[n].flight_num, flight[n].seat_num, flight[n].first, flight[n].last);
	printf("\nWhich seat do you want to delete (0 to back):\n\n");
	while (scanf("%d", &n) && n > 0 && n <= MAXSEAT)
	{
		while (getchar() != '\n');
		if (flight[--n].own)
		{
			flight[n].own = false;
			strcpy(flight[n].first, "");
			strcpy(flight[n].last, "");
			flight[n].confirm = false;
		}
		else
			printf("\nIt is empty, try again!\n");
		printf("\nWhich seat do you want to delete (0 to back):\n\n");
	}
	while (getchar() != '\n');
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
