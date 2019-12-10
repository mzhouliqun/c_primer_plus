#include <stdio.h>
#include <stdlib.h>
#define MAX 12
struct seat{
	int number;
	int assign;
	char lastname[10];
	char firstname[10];
};
struct seat seats[MAX]={ //缺省设置
	{101,0},
	{102,0},
	{103,0},
	{104,0},
	{105,0},
	{106,0},
	{107,0},
	{108,0},
	{109,0},
	{110,0},
	{111,0},
	{112,0}
};
void read_file(struct seat *p, char* filename);
void choose(void);
void show_number_empty(struct seat *p);
void show_list_empty(struct seat *p);
void show_list(struct seat *p);
void assign_seat(struct seat *p);
void delete_seat(struct seat *p);
void write_file(struct seat *p, char* filename);
int main(void)
{
	read_file(seats, "seat.dat");
	while (1)
		choose();
	return 0;//此句无用
}
void read_file(struct seat *p, char* filename)
{
	FILE * pseats;
	if ((pseats = fopen(filename, "rb")) == NULL)
		printf("Can't open %s file. So load default data.\n", filename);
	else
	{
		rewind(pseats); /* go to start of file */
		while (fread(p, sizeof(struct seat), MAX, pseats) == 1) continue;
		fclose(pseats);
		printf("read %s successfully!\n", filename);
	}
}
void choose(void)
{
	char command[10];
	printf("\nTo choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
	gets(command);
	switch (command[0])
	{
		case 'a': show_number_empty(seats); break;
		case 'b': show_list_empty(seats); break;
		case 'c': show_list(seats); break;
		case 'd': assign_seat(seats); break;
		case 'e': delete_seat(seats); break;
		default : write_file(seats,"seat.dat"); puts("Quit"); exit(1);
	}
}
void show_number_empty(struct seat *p)
{
	int i,n;
	for (i=0, n=0; i<MAX; i++)
		if ( p[i].assign == 0 )
			n++;
	printf("There are %d empty seats\n",n);
}
void show_list_empty(struct seat *p)
{
	int i;
	printf("empty seats:\n");
	for (i=0; i<MAX; i++)
		if (p[i].assign == 0 )
			printf("number %d\n", p[i].number);
}
void show_list(struct seat *p)
{
	int i;
	printf("seat list:\n");
	for (i=0; i<MAX; i++)
	{
		printf("number %d\t", p[i].number);
		if (p[i].assign == 1)
			printf("full %s %s\n", p[i].firstname, p[i].lastname );
		else
			printf("empty\n");
	}
}
void assign_seat(struct seat *p)
{
	int number, i;
	printf("Input the seat number:");
	scanf("%d", &number);
	 getchar();
	 for (i=0; i<MAX; i++)
		 if ( p[i].number == number)
		 {
			 if (p[i].assign == 1)
				 printf("NO.%d seat is already assigned!\n", p[i].number);
			 else
			 {
				 printf("Input firstname of the holder:");
				 scanf("%s", p[i].firstname);
				 printf("Input lastname of the holder:");
				 scanf("%s", p[i].lastname);
				 getchar();
				 p[i].assign = 1;
				 printf("assign NO.%d seat successfully!\n", p[i].number);
			 }
			 return;
		 }
	 printf("%d is a invalid seat number!\n", number);
}
void delete_seat(struct seat *p)
{
	int number, i;
	printf("Input the seat number:");
	scanf("%d", &number);
	getchar();
	for  (i=0; i<MAX; i++)
		if (p[i].number == number)
		{
			if (p[i].assign == 0)
				printf("NO.%d seat is already empty!\n", number);
			else
			{
				p[i].assign = 0;
				printf("delete NO.%d seat successfully!\n", number);
			}
			return;
		}
	printf("%d is a invalid seat number\n", number);
}
void write_file(struct seat *p, char* filename)
{
	 FILE * pseats;
	 if ((pseats = fopen(filename, "wb")) == NULL)
	 {
		 printf("Can't open %s file.", filename);//将文件以可写模式打开，没有则创造，清空文件内
			 exit(1);
	 }
	 fwrite(p, sizeof(struct seat), MAX, pseats);
	 fclose(pseats);
}
