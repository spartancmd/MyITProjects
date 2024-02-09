#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int* ptr;
    unsigned lenght;
};

struct Array createArray(unsigned len, int val)
{
    struct Array ar;
    ar.lenght = len;
    ar.ptr = malloc(len);

    for (unsigned i = 0; i < len; i++)
        ar.ptr[i] = val;

    return ar;
}

struct Array unite(struct Array ar1, struct Array ar2)
{
    struct Array result = createArray(ar1.lenght + ar2.lenght, 0);

    for (unsigned i = 0; i < ar1.lenght + ar2.lenght; i++) 
    {
        if (i < ar1.lenght)
            result.ptr[i] = ar1.ptr[i];
        else
            result.ptr[i] = ar2.ptr[i - ar1.lenght];
    }

    return result;
}

void freef(struct Array* ar)
{
    free(ar->ptr);
    ar->lenght = 0;
    ar->ptr = NULL;
}

void print_array(struct Array ar)
{
    for (unsigned i = 0; i < ar.lenght; i++)
        printf("[%i] %d\n", i, ar.ptr[i]);
}

int main()
{
    int lenght = 10;
    struct Array ar1 = createArray(lenght, 5);
    struct Array ar2 = createArray(lenght, 7);

    printf("Result 1:\nLenght = %d\nElements:\n", ar1.lenght);
    print_array(ar1);
    print_array(ar2);

    struct Array newm = unite(ar1, ar2);

    printf("\nResult 2:\nUnited elements:\n");
    print_array(newm);

    freef(&ar1);
    freef(&ar2);
    freef(&newm);

    printf("\n\nMemory cleared.");

    return 0;
}