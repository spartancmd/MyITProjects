#define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// #define MAX_SIZE 20
// #define DEBUG // macros

// void f()
// {
// #ifdef DEBUG
//     printf("debugging...\n");
//     // ...
// // #else
// //     printf("not debugging...\n");
// #endif

//     // a lot of useful code
// }

// #pragma pack 1;

extern int printf (const char *__restrict __format, ...);

void f(); // declaration of function

// void f() { // definition of function
//     printf("Hello, world!");
// }

int main()
{
    int x; // declaration

    int a = 0; // definition

    // f();
    printf("Hello, world!");

    return 0;
}
