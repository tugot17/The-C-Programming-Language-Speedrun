//gcc file_with_variables.c importing_external_variables.c -o myProgram

// importing_external_variables.c
#include <stdio.h>
#include "variables.h"

void printVars() {
    printf("myGlobalVar: %d\n", myGlobalVar);
    printf("anotherGlobalVar: %f\n", anotherGlobalVar);
}

int main() {
    printVars();
    return 0;
}
