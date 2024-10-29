#include <stdio.h>
#include <ctype.h>
int main() /* lower: convert input to lower case*/
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(tolower(c)); // how does this work?
    // where is the implementation of stdio? why we don't need to compile this by hand?
    return 0;
}