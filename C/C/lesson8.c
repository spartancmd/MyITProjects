#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void print_array(int* a)
//{
//	while (*a != 0)
//	{
//		printf("%d ", *a);
//		a++;
//	}
//
//	//int n = b - a; // length of data range [a, b)
//
//	/*while (a != b) {
//		printf("%d ", *a);
//		a++;
//	}*/
//}

int x; // BSS segment
int y = 5; // Data segment

int main() {
	//char s[7] = "Hello!";

	//printf("%s", s);

	//char* s = "Hello";
	//strcpy(s, "Hello");

	//char* s = _strdup("Hello");

	/*free("Hello");*/   // error
	//s[0] = 'S'; // error happens
	//printf("%s", s);

	//printf("%p\n", &"Hello");
	//printf("%p\n", &"%p");

	/*int a[6] = { 1, 2, 3, 4, 5, 6 };
	print_array(a);*/

	return 0;
}