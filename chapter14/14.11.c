#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#define RANGE 1000
#define LENGTH 100
static unsigned int next = 1;
int mytime(void);
void srand1(unsigned int);
int rand1(void);
double create_double(void);
void create_double_array(double *);
void transform(double *, double *, int , double (*pfun)(double));
void showmenu(void);
double opposite(double);
double square_root(double);
char *s_gets(char *, int);

int main(void)
{
	int i = 0;
	double source[LENGTH] = {0.0};
	double target[LENGTH] = {0.0};
	double (*pfun)(double);
	char command[10];

	create_double_array(source);
	showmenu();
	while (1)
	{
		s_gets(command, 2);
		switch(command[0])
		{
			case 'a': pfun = sin; break;
			case 'b': pfun = cos; break;
			case 'c': pfun = opposite; break;
			case 'd': pfun = square_root; break;
			case 'q': printf("\nBye!\n"); return 0;
			default : printf("\nInput error! Select: a/b/c/d/q:\n\n"); continue;
		}
		transform(source, target, LENGTH, pfun);
		printf("\nSelect: a/b/c/d/q:\n\n");
	}
	return 0;
}

void transform(double *source, double *target, int max, double (*pfun)(double))
{
	int i;
	char fun[20];

	if (pfun == sin)
	{
		printf("\nThe calculation of sine:\n\n");
		strcpy(fun, "sin");
	}
	if (pfun == cos)
	{
		printf("\nThe calculation of cosine:\n\n");
		strcpy(fun, "cos");
	}
	if (pfun == opposite)
	{
		printf("\nThe calculation of opposite:\n\n");
		strcpy(fun, "opposite");
	}
	if (pfun == square_root)
	{
		printf("\nThe calculation of square root:\n\n");
		strcpy(fun, "square_root");
	}

	for (i = 0; i < max; i++)
	{
		target[i] = pfun(source[i]);
		printf("source[%d]:\t%lf\t\t%s (%lf) =\t%12lf\n", i, source[i], fun, source[i], target[i]);
	}
}

void showmenu(void)
{
	printf("\nSelect the function you want to use:\n");
	printf("a) sin\n");
	printf("b) cos\n");
	printf("c) opposite number\n");
	printf("d) square root\n");
	printf("q) quit\n\n");
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

double opposite(double n)
{
	return(-1 * n);
}

double square_root(double n)
{
	double x = 0.0;
	double y = n / 2;

	while (x != y)
	{
		x = y;
		y = (x + n / x) / 2;
	}
	return x;
}

void create_double_array(double *num)
{
	int i = 0;

	printf("Source value:\n");
	for (i = 0; i < LENGTH; i++)
	{
		num[i] = create_double ();
		printf("source[%d]:\t%lf\n", i, num[i]);
	}
	printf("\n");
}

double create_double(void)
{
	int m;
	int n;

	unsigned seed;
	seed =(unsigned int) mytime();
	srand1(seed);
	m = rand1();
	sleep(1);
	while ((n = rand1()) == 0);
	return((double) m / (double) n);
}

int mytime(void)
{
        int seconds = time((time_t *)NULL);
        return seconds;
}

int rand1(void)
{
	next = next * 1103515245 + 12345;
	return((unsigned int)(next / 65536) % RANGE);
}

void srand1(unsigned int seed)
{
	next = seed;
}
