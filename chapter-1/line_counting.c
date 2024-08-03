//Exercise 1-8
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, blanks=0, tabs=0, newlines=0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++newlines;
        else if (c == '\t')
            ++tabs;
        else if (c == ' ')
            ++blanks;
    }

    printf("Blanks %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
    
    return 0;
}
