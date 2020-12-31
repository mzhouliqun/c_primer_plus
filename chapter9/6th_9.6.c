#include <stdio.h>
void alter(int *, int *);
int main(void)
{
	int a = 5;
	int b = 6;

	printf("original: a = %d, b = %d\n", a, b);
	alter(&a, &b);
	printf("exchanged: a = %d, b = %d\n", a, b);
	return 0;
}

void alter(int *m, int *n)
{
	int tempa = *m;
	int tempb = *n;

	*m = tempa + tempb;
	*n = tempa - tempb;
}
