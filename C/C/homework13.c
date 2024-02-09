#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    // Least Common Multiple
    int range_begin = a, range_end = a * b;
    int res = range_end; // такое число, что min(любое число, res) = любое число

    for (int i = range_begin; i <= range_end; ++i)
    {
        if (i % a == 0 && i % b == 0)
        {
            if (i < res)
                res = i;
        }
    }

    printf("LCM IS %d\n", res);
}

