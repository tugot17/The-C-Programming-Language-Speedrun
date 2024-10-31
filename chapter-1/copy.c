#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;

    while((c = getchar()) != EOF)
    {
        putchar(c);
    }

    printf("EOF encountered. The value of EOF is: %d\n", EOF);
        

    return 0;
}
