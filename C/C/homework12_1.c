#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 13;

	for (int b = 1; b <= 1000; b++)
	{
		if (b % a == 0)
			printf("%d\n", b);
	}

	scanf("%d", &a);

	for (int b = 1; b <= 1000; b++)
	{
		if (b % a == 0)
			printf("%d\n", b);
	}

}