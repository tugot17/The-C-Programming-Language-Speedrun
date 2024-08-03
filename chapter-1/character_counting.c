#include <stdio.h>

int main(int argc, char const *argv[])
{
    double nc;
    for (double nc = 0; getchar() != EOF; ++nc)
        ; //null statement

    printf("\n%.0f\n", nc);

    return 0;
}
