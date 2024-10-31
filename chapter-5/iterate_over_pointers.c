#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int *ptr = arr;  // or int *ptr = &arr[0];

    // iterate over the array and show what happens if we get into unallocated piece of memory    
    for (int i = 0; i < 10; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}
