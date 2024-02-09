// #include <stdio.h>
// #define addi(a, b) a + b;
// #define addd(a, b) a + b;
// #define addc(a, b) a + b;

// int main()
// {
//     int x = addi(4, 5);
//     double d = addd(3.14, 3.14);
//     char c = addc(1, 1);

//     printf("int x = %d\ndouble d = %f\nchar c = %c", x, d, c);

//     return 0;
// } 

#include <stdio.h>
// #define addi(a, b) a + b
// #define addd(a, b) a + b
// #define addc(a, b) a + b

#define generate_func(name, type)  type name(type a, type b) \
                    { \
                        return a + b; \
                    }

#define MAX_SIZE 20

generate_func(addi, int)
generate_func(addd, double)
generate_func(addf, float)
generate_func(addc, char)

int main()
{
    int a = 1;
    int b = 0;

    printf("%d\n", a);
    printf("%d\n", b);
    return 0;

    int x = addi(4,5);
    double d = addd(3.14, 3.14);
    char c = addc(1,1);

    printf("int x = %d\ndouble d = %f\nchar c = %c", x, d, c);

    return 0;
}