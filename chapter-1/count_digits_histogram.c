//Exercise 1-14
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, n_white=0, n_other=0;

    int ndigit[10] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++n_white;

        else
            ++n_other;
    }

    int i = 0;
    for (i=0; i < 10; ++i)
    {   
        printf("%d: ", i);
        for (int j=0; j < ndigit[i]; ++j)
            printf("-");
        printf("\n");
    }
        
    return 0;
}
