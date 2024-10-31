#include <stdio.h>

#define IN 1  
#define OUT 0

int main(int argc, char const *argv[])
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                putchar('\n');  // End the word with a newline
                state = OUT;
            }
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }

    if (state == IN)
        putchar('\n');

    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
    return 0;
}