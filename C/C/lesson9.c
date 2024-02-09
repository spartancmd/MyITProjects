#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int a; // field
	char b; // field
} A;


struct Array {
	int* a;
	int n;
};

//void print_array(struct Array arr)
//{
//	for (int i = 0; i < arr.n; i++)
//		printf("%d ", arr.a[i]);
//}
//
//void fill_array(struct Array arr, int val)
//{
//	for (int i = 0; i < arr.n; i++)
//		arr.a[i] = val;
//}
//
//// add each element of second array to each element of first array
//void add_array(int* a1, int n1, int* a2, int n2)
//{
//	if (n1 != n2) 
//	{ 
//		printf("Error! len of first array is not equal to len of second arr");
//		return;
//	}
//
//	for (int i = 0; i < n1; i++)
//		a1[i] += a2[i];
//}

typedef int Int;
typedef int integer;
typedef int Integer;

struct S {
	char name[21];
	int x;
};

#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int* ptr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		ptr[i] = i + 1;
	}
	int* a = &ptr[n - 1];
	for (int i = 0; i < n; i++, a--)
	{
		printf("%d \t", *a);
	}
}

//int main() {

	//Int a;
	//int x;
	//integer y;
	//Integer z;
	//A variable = { 1, 'a' }; // initializer list

	//printf("%d %c", variable.a, variable.b);
	
	//struct Array arr;
	//arr.n = 5;
	//arr.a = (int*)calloc(5, sizeof(int));

	//fill_array(arr, 5);
	//print_array(arr);

//	return 0;
//}