#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int* a = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("Input number %d\n", i);
		scanf("%d", &a[i]);
	}

	int begin = 3;
	int end = begin + n;

	for (int i = begin; i < end; i++) {
		printf("%d ", a[i % n]);
	}

	// begin, end
	// 3, 4, 5, 6
	// возьмём от них % n (n = 4)
	// 3, 0, 1, 2
}