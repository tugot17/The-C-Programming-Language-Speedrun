#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n);
void afree(char *p);

int main() {
    char *p1, *p2;

    p1 = alloc(100);
    if (p1 != NULL) {
        printf("Allocated 100 bytes.\n");

        // Initialize the allocated memory with 'A'
        for (int i = 0; i < 100; i++) {
            p1[i] = 'A';
        }

        // Print the content of the first few bytes of p1
        printf("First few bytes of p1: ");
        for (int i = 0; i < 10; i++) {
            printf("%c ", p1[i]);
        }
        printf("\n");
    } else {
        printf("Allocation failed for 100 bytes.\n");
    }

    printf("Offset p1 by 50\n");
    p1 += 50;

    printf("First few bytes of offest p1: ");
    for (int i = 0; i < 10; i++)
        printf("%c ", p1[i]);
    printf("\n");



    p2 = alloc(5000);
    if (p2 != NULL) {
        printf("Allocated 5000 bytes.\n");
    } else {
        printf("Allocation failed for 5000 bytes.\n");
    }

    afree(p2);
    printf("Freed 5000 bytes.\n");

    char *p3 = alloc(300);
    if (p3 != NULL) {
        printf("Allocated 300 bytes.\n");
    } else {
        printf("Allocation failed for 300 bytes.\n");
    }

    return 0;
}

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {  
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}
