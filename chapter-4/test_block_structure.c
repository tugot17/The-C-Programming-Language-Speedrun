#include <stdio.h>

int main(int argc, char const *argv[])
{

    if (1==1) {
        int i = 10;
    }

    printf("I+1= %d", i+1); //this fails cause i is in scope of the if
    
}
