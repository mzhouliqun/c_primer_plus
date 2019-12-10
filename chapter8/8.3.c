#include <stdio.h>
int main(void)
{

        int ch;
        int dcount = 0;
        int xcount = 0;

        while ((ch = getchar()) != EOF)
        {
                if (ch >= 65 && ch <= 90)
                        dcount++;
                if (ch >= 97 && ch <= 122)
                        xcount++;
        }
        printf("Capital letters is %d, lowercase letters is %d.\n", dcount, xcount);
        return 0;
}
