#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int add(int x, int y) { return x + y; }

void test() // процедура
{
    assert(add(3, 5) == 3 + 5);
    assert(add(-1, 5) == -1 + 5);
    assert(add(1, -5) == 1 + -5);
    assert(add(-1, -5) == -1 + -5);
}

void swap(int* ptr_x, int* ptr_y)
{
    int temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
}

void swap_if(int* ptr_x, int* ptr_y, int* ptr_z, int* ptr_w, int (*f)(int, int))
{
    if (
            !f(*ptr_x, *ptr_y) // f вернула 0
        )
        swap(ptr_x, ptr_y);
    
    if (!f(*ptr_y, *ptr_z))
        swap(ptr_z, ptr_y);
    if (!f(*ptr_z, *ptr_w))
        swap(ptr_z, ptr_w);
}

int greater(int x, int y) {
    if (x > y)
        return 1; // true
    return 0;
}

int less(int x, int y) {
    if (x < y)
        return 1; // true
    return 0;
}

int main()
{
    int (*ptr)(int, int) = add; // &add - необязателен амперсант
    void (*ptr2)() = test;

    ptr(3, 5); // (*ptr)(3, 5) - необязательно разыменование указателя ptr

    ptr2();

    int a = 5, b = 3, c = 7, d = 8;
    swap_if(&a, &b, &c, &d, less);
    printf("%d %d %d %d", a, b, c, d);

    return 0;
}