//Exercise 1.15
#include <stdio.h>


float get_celcius_from_farenheit(int fahr){
    return (5.0/9.0) * (fahr-32);
}

int main()
{

    #define LOWER 0 
    #define UPPER 300 
    #define STEP 20 

    printf("%3s %6s\n", "Farenheit", "Celcius");

    for (int fahr = UPPER; fahr >=LOWER ; fahr = fahr-STEP)
    {
        printf("%6d %6.1f\n", fahr, get_celcius_from_farenheit(fahr));
    }
}
