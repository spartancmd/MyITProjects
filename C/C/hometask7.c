#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }

int main()
{
	int n = 10;
	int* a = (int*)malloc(sizeof(int) * n);

	/*int n = 100000000;
	char* a = (char*)calloc(n, sizeof(char));
	free(a);
	a = (char*)calloc(n / 1000, sizeof(char));
	
	a[0] = 0;
	if (a != NULL)
		printf("%d", a[0]);*/


	return 0;
}