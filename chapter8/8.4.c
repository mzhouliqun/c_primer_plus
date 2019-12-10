#include <stdio.h>
#include <ctype.h>
int main(void)
{

        int ch;
        int num;
        _Bool keyword = 0;

        while ((ch = getchar()) != EOF)
        {
                if (isalpha(ch) && !keyword)
                {
                        keyword = 1;
                        num++;
                }

        if (!isalpha(ch))
                keyword = 0;
        }
        printf("words: %d\n", num);
        return 0;
}

