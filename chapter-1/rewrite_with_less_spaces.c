//Exercise 1-9
#include <stdio.h>

int main()
{
    int prev_c=-1, c;

    while ((c = getchar()) != EOF)
    {
        if (prev_c != ' ' || c != ' ')
            putchar(c);

        prev_c=c;
    }
    

    return 0;
}