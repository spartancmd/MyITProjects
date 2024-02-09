#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>


int main(void)
{
	int a = 0;
	scanf("%d", &a);

	if (a < 0 && a > -5 || a > 10) // disjunction
		printf("(a < 0 and a > -5) or a > 10");
	
	//int val = (a == 0) ? 1 : 0; // int val = (a == 0);

	//if (a == 0)
	//	printf("hello world");
	//else if (a > 1)
	//	printf("bye-bye world");
	// a < 0 or a == 0 or a == 1 or a == 2 or a == 3 or a == 4 or a > 4
	//switch (a)
	//{
	//case 0:
	//	printf("a = 0");
	//case 1:
	//	printf("a = 1");
	//case 2:
	//	printf("a = 2");
	//case 3:
	//	printf("a = 3");
	//case 4: // a == 4
	//	printf("a = 4");
	//default: // else
	//	printf("by default");
	//}

	//if (a < 0)
	//	printf("a < 0\n");
	//else if (a == 0)
	//	printf("a = 0\n");
	//else if (a == 1)
	//	printf("a = 1\n");
	//else if (a == 2)
	//	printf("a = 2\n");
	//else if (a == 3)
	//	printf("a = 3\n");
	//else if (a == 4)
	//	printf("a = 4\n");
	//else if (a > 4)
	//	printf("a > 4\n");
	//if (!a) // 0 <-> false; not 0 <-> true
	//{
	//	printf("a is equal to 0!\n");
	//}

	/*printf("x and y: %d\n", x && y);
	printf("x or y: %d\n", x || y);
	printf("not x: %d\n", x != y);*/
	
	//const float pi = 3.14;

	//// 0 - false, 1 - true
	//printf("a == b: %d\n", a == b); // are equal
	//printf("a != b: %d\n", a != b); // are not equal
	//printf("a > b: %d\n", a > b); // greater then
	//printf("a < b: %d\n", a < b); // less then
	//printf("a >= b: %d\n", a >= b); // greater or equal then
	//printf("a <= b: %d\n", a <= b); // less or equal then

	// a--; postfix decrement
	/*printf("%d\n", a--);
	printf("%d\n", a);
	printf("%d\n", --a);
	printf("%d\n", a++);
	printf("%d\n", a);
	printf("%d\n", ++a);*/

	//--a; // prefix decrement
	//++a; // prefix increment
	//a++; // postfix increment

	// a++ <=> a = a + 1
	// --a <=> a = a - 1;

	//printf("%d", a % b);

	/*scanf("%d", &a);
	float f = (double)a / b;
	printf("%f", f);*/

	//printf("%d", 1 + 2 * 3 - 8 % 3);

	
	return 0;
}