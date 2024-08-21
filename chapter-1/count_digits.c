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

    printf("digits =");
    for (int i=0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    
    printf(", white space = %d, other = %d\n", n_white, n_other);

    return 0;
}
