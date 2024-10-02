#include <stdio.h>


int main(int argc, char const *argv[])
{
    int i, j;

    int first[] = {1, 2, 3, 4, 5};
    int second[] = {122, 22, 3, 14, 55};

    int m = sizeof(first)/sizeof(first[0]);
    int n = sizeof(second)/sizeof(second[0]);


    for(i =0; i < m; i++)
        for(j=0; j < n; j++)
            if (first[i] == second[j])
                goto found;

    printf("No same numbers in arrays");
    return 0;

    found: 
        printf("The common number is: %d\n", first[i]);

    return 0;
}

