#include <stdio.h>

int main() {
    int a = 5, b = 5;
    int result1, result2;

    // Using postfix increment
    result1 = a++;
    printf("After a++: a = %d, result1 = %d\n", a, result1);

    // Reset a
    a = 5;

    // Using prefix increment
    result2 = ++a;
    printf("After ++a: a = %d, result2 = %d\n", a, result2);

    // Demonstrating in a more complex expression
    a = b = 5;
    printf("\nComplex expression:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a++ + ++b = %d\n", a++ + ++b);
    printf("After expression: a = %d, b = %d\n", a, b);

    return 0;
}