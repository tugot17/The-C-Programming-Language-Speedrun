#include <stdio.h>

int main()
{
    int age;
    float height;
    printf("Enter your age and height: ");
    scanf("%d %f", &age, &height); // Expecting an integer and a float

    printf("Age: %d, Height: %.2f\n", age, height);
    return 0;
}
