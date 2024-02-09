#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x = 0; // definition
	int y = 0; // definition

	printf("Input two values to get sum (separate by space)\n");
	scanf("%i %i", &x, &y); // scan formattly two integer

	printf("Sum is %i", x + y);
	//int z = 0;
	//z = x + 2 * y;

	//printf("x is %i, y is %i, z is %i", x, y, z); // integer

	/*x = 3;
	y = 4;
	printf("x is %i", x); integer*/

	//printf("Hello\n"); // print with formatting
	//printf("world");
	_getch();
	return 0;
}