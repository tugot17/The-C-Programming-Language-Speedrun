//Exercise 1-14
#include <stdio.h>

#define MAX_HEIGHT 10

int main(int argc, char const *argv[])
{
    int c, n_white = 0, n_other = 0;
    int ndigit[10] = {0};
    int max_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++n_white;
        else
            ++n_other;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (ndigit[i] > max_count)
            max_count = ndigit[i];
    }

    float scale = (max_count > MAX_HEIGHT) ? (float)MAX_HEIGHT / max_count : 1;

    for (int height = MAX_HEIGHT; height > 0; --height)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (ndigit[i] * scale >= height)
                printf("| ");
            else
                printf("  ");
        }
        printf("\n");
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", i);
    printf("\n");

    return 0;
}