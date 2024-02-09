
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Array {
    int* ptr;
    unsigned len;
};

struct Array createArray(unsigned len, int val)
{
    struct Array ar;
    ar.len = len;
    ar.ptr = malloc(len);

    for (unsigned i = 0; i < len; i++)
        ar.ptr[i] = val;

    return ar;
}

struct Array filter(struct Array arr, int (*filter_func)(int))
{
    struct Array result;
    unsigned length = 0;

    for (unsigned i = 0; i < arr.len; i++)
    {
        if (filter_func(arr.ptr[i]) == true)
            length++;
    }
    
    result = createArray(length, 0);
    for (unsigned idx = 0, i = 0; i < arr.len; i++)
    {
        if (filter_func(arr.ptr[i]) == true) {
            result.ptr[idx] = arr.ptr[i];
            idx++;
        }
    }

    return result;
}

void print_array(struct Array ar)
{
    for (unsigned i = 0; i < ar.len; i++)
        printf("[%i] %d\n", i, ar.ptr[i]);
}

// int greater(int x)
// { 
//     if (x > 10000)
//         return true;
//     return false;
// }

// int less(int x) 
// {
//     if (x < 10000)
//         return true;
//     return false;
// }

struct Array create_random_array(unsigned len)
{
    struct Array arr = createArray(len, 0);
    for (unsigned i = 0; i < len; i++)
        arr.ptr[i] = rand();

    return arr;
}

int less(int* x, int* y)
{
    return *x < *y;
}

int greater(int* x, int* y)
{
    return *x > *y;
}

int main()
{
    // struct Array arr = create_random_array(20);
    // print_array(arr);
    // struct Array res = filter(arr, less);
    // print_array(res);

    int a[] = {4 , 5,6 , 2, 6 ,2 ,55, 2};
    qsort(a, 8, sizeof(int), greater);
    for (int i = 0; i < 8; i++)
    printf("%d\n", a[i]);

    return 0;
}