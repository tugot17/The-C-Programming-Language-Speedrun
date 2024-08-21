#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_increasing_random_array(int length, int min_start, int max_gap) {
    int* arr = (int*)malloc(length * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    arr[0] = min_start + (rand() % max_gap);
    
    for (int i = 1; i < length; i++) {
        // Ensure each number is greater than the previous one
        arr[i] = arr[i-1] + 1 + (rand() % max_gap);
    }
    
    return arr;
}


int binsearch_original(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}


int binsearch_modified(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (v[low] == x) ? low : -1;
}


void measure_runtime(int (*search_func)(int, int[], int), int arr[], const int n, const int x, const char* func_name){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int result = search_func(x, arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s: Result = %d, Time = %f seconds\n", func_name, result, cpu_time_used);
}


int main(int argc, char const *argv[])
{   
    int n = 100;
    int min_start = 1;
    int max_gap = 10;

    srand(time(NULL));
    int* arr = create_increasing_random_array(n, min_start, max_gap);

    printf("Array contents:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int x = 22;

    measure_runtime(binsearch_original, arr, n, x, "Binearch Original");
    measure_runtime(binsearch_modified, arr, n, x, "Binearch Modified");

    free(arr);

    return 0;
}
