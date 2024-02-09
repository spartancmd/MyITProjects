#include "headers.h"

void bubbleSort(int* a, unsigned n);
void printArray(int* a, unsigned n);
int isSorted(int* a, unsigned n);
int* generateRandomArray(unsigned size);

int main() {
    unsigned cnt = 10;
    for (unsigned i = 0; i < cnt; i++) {
        unsigned n = 10000;
        int* a = generateRandomArray(n);

        clock_t begin_time = clock();
        bubbleSort(a, n);
        clock_t finish_time = clock();
        
        if (!isSorted(a, n)) {
            printf("Error!!!\n");
            free(a);
            return 1;
        }

        printf("BubbleSort spend %f seconds\n", (double)(finish_time - begin_time) / CLOCKS_PER_SEC);

        free(a);
    }
    return 0;
}