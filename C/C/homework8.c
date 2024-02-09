#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_array(int* ptr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ptr[i]);
	}
	return;
}

void swap(int* ptr, int* ptr2 )
{
	int temp = *ptr;
	*ptr = *ptr2;
	*ptr2 = temp;
}

// 0 1 2 3
//   i j
// (n - 1) / 2 = 1 since (n = 4)

void full_reverse(int* ptr, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(&ptr[i], &ptr[j]);
        i++;
        j--;
    }
}

void reverse(int* ptr, int n, int k)
{
	full_reverse(ptr, k);
}

int main()
{
	int n = 8, k = 5;
	scanf("%d %d", &n, &k);
	int* ptr = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		ptr[i] = i + 1;
	}

	printf("Before\n");
	print_array(ptr, k);
	reverse(ptr, n, k);
	printf("\nAfter\n");
	print_array(ptr, k);
	
    return 0;
}