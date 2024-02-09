#include <stdio.h>

int main()
{
    const double pi = 3.1415;

    // pi = 4.5; // не может быть необходимым

    double* ptr = &pi;
    *ptr = 4.5; // undefined behaviour

    printf("%f", pi);

    return 0;
}