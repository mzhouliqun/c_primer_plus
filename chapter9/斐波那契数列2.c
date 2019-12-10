#include<stdio.h>
int a[201][101]={0};
int b[201][101]={0};
int c[201][101]={0};
int n;
int main()
{

	int i, j, k;

	printf ("This program is used to calculate the term of the Fibonacci sequence.\n");
	printf ("Enter an integer (q to quit):\n");
	while (scanf ("%d",&n) != 1);
	for (k=1; k<=n; k++)
	{
		if (k<3)
			printf ("%d\n",1);
		else if (k == 3)
			printf ("%d\n",2);
		else
		{
			c[k][1]=2;
			b[k][1]=1;
			for (i=1; i<=k-3; i++)
			{
				for (j=1; j<=100; j++)
				{
					a[k][j]=b[k][j];
					b[k][j]=c[k][j];
					c[k][j]=0;
				}
				for (j=1;j<=100;j++)
				{
					c[k][j] = c[k][j] + a[k][j] + b[k][j];
					if (c[k][j] >= 10)
					{
						c[k][j] = c[k][j] - 10;
						c[k][j+1] = 1;
					}
				}
			}
			i=100;
			while ( c[k][i] == 0)
				i--;
			for (i=i; i >= 1; i--)
				printf ("%d", c[k][i]);
			printf("\n");
		}
	}
	return 0;
}
