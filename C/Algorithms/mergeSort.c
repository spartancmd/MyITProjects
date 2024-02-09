#include <stdio.h>
#include <stdlib.h>

int* merge(int* a, size_t n, int* b, size_t m) {
    // printf("Allocating %d ints\n", n + m);
    int* result = (int*)malloc(sizeof(int) * (n + m));

    size_t i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            result[i + j] = a[i];
            ++i;
        }
        else {
            result[i + j] = b[j];
            ++j;
        }
    }

    while (i < n) {
        result[i + j] = a[i];
        ++i;
    }
    while (j < m) {
        result[i + j] = b[j];
        ++j;
    }

    return result;
}

int* mergeSort(int* begin, size_t n) {
    if (n == 1) {
        int* result = malloc(sizeof(int));
        *result = *begin;
        return result;
    }

    int* a = mergeSort(begin, n / 2); // left
    int* b = mergeSort(begin + n / 2, n - (n / 2)); // right
    int* result = merge(a, n / 2, b, n - (n / 2));
    
    free(a);
    free(b);
    return result;
}


int main() {
    int a[] = {0, 1, 4 ,1 ,3,4 , 5, 2, 5, 1, 6, 7, 1 , 5};
    size_t n = sizeof(a) / sizeof(int);
    int* result = mergeSort(a, n);
    for (size_t i = 0; i < n; i++)
        printf("%d ", result[i]);
    
    free(result);

    return 0;
}