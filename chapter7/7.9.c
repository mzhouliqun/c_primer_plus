#include <stdio.h>
int isprime(int);
int main(void)
{

        int num, i;
        printf("Please enter a positive integer, program will calculate all the positive numbers that less than your input:");
        while (scanf("%d", &num) == 1)
        {
                if (num <= 1)
                {
                        printf("Input Error, please input again!\n");
                        continue;
                }
                printf("The prime <= %d is :\n", num);
                for (i = 2; i <= num; i++)
                if (isprime(i))
                        printf("%d\n", i);
                break;
        }
        return 0;
}
int isprime(int n)
{
        int div;
        for (div = 2; div * div <= n; div++)
                if (n % div == 0)
                        return 0;
        return 1;
}
