#include "headers.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* a, unsigned n) {
    for (unsigned i = 0; i < n - 1; i++)
    {
        for (unsigned j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a + j, a + j + 1);
            }
        }
    }
}

void printArray(int* a, unsigned n) {
    for (unsigned i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int isSorted(int* a, unsigned n) {
    for (unsigned i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return 0;
    }

    return 1;
}

int* generateRandomArray(unsigned size) {
    int* a = (int*)malloc(sizeof(int) * size);
    for (unsigned i = 0; i < size; i++) {
        a[i] = rand();
    }

    return a;
}