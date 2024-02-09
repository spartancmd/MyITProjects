#include <stdio.h>


int* binarySearch(int* a, unsigned n, int x) {
    if (n == 0)
        return NULL;
    if (n == 1) {
        if (a[0] == x)
            return a;
        return NULL;
    }

    unsigned mid = n / 2;
    if (a[mid] == x)
        return a + mid;
    if (x < a[mid]) // we should search only in left part
        return binarySearch(a, mid, x);
    if (x > a[mid]) // we should search only in right part
        return binarySearch(a + mid + 1, n - mid - 1, x);
}

int main() {
    int a[] = {1, 2, 4, 6, 7 , 8, 10, 12, 15};
    unsigned n = sizeof(a) / sizeof(int);

    for (int wanted = -10; wanted < 20; wanted++) {
        int* res = binarySearch(a, n, wanted);
        
        if (res == NULL)
            printf("No such element: %d\n", wanted);
        else
            printf("Found element %d\n", wanted);
    }

    return 0;
}