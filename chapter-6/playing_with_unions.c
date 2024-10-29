#include <stdio.h>

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;
    printf("data.f: %f\n", data.f);

    // Writing to data.str overwrites data.f because they share memory
    snprintf(data.str, sizeof(data.str), "Hello");
    printf("data.str: %s\n", data.str);

    // Accessing data.i or data.f now would not be reliable since data.str has overwritten them
    return 0;
}
