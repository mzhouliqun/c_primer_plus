#include <stdio.h>
#define PRINCIPAL 100
int main(void)
{
	int i = 0;
	double daphne = PRINCIPAL;
	double deirdre = PRINCIPAL;

	do
	{

		deirdre *= 1.05;
		daphne += (PRINCIPAL * 0.1);
		i++;
	} while (deirdre <= daphne);

	printf("In %d years Deirdre will surpass Daphne.\n", i);
	printf("Deirdre:%20lf\n", deirdre);
	printf("Daphne: %20lf\n", daphne);
	return 0;
}
