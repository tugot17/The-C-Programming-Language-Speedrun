#include <stdio.h>

int main() {
    int bits = sizeof(int) * 8;
    int max_int = (1LL << (bits - 1)) - 1;
    int min_int = -(1LL << (bits - 1));

    printf("\n In GCC Compiler \n");
    printf("The size of integer is: %zu Bytes\n", sizeof(int));
    printf("Min range Integer value is: %d\n", min_int);
    printf("Max range Integer value is: %d\n", max_int);

    return 0;
}