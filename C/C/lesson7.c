// FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void greet_user()
{  // scope, скоуп
	char name[20];
	printf("Input your name!\n");
	scanf("%s", name); // hope user won't input name longer than 20 characters
	printf("Hello, %s\n", name);
}

void print_greeting_words()
{
	printf("Hello, dear user!\n");
	printf("We are glad that you've decided to use our program!\n");
	printf("Have a nice day!\n");
}

// passing args to function
int print_sum(int x, int y)
{
	printf("A (%d) + B (%d) = %d\n", x, y, x + y);

	return x + y;
}



/*int get_mult(int x, int y)
{
	return x * y;
}*/

void C()
{
	printf("Inside C\n");
}

void B()
{

	printf("Inside B\n");
}

void A(int a, int b) // a, b - parameters/arguments
{
	int res = 0; // local variable of function A
	C();
	printf("Inside A\n");
	B();
}



//void change_value(int* ptr)
//{
//	//x = 7;
//	*ptr = 7;
//}

/*void get_sum(int a, int b, int* res)
{
	*res = a + b;
}*/

// swap values between two variables
void swap(int* ptr_a, int* ptr_b)
{
	int temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}


int main()
{
	int a = 4, b = 6;

	swap(&a, &b);
	printf("[main] a: %d, b: %d\n", a, b);

	//int res = 0;
	//get_sum(a, b, &res);
	//printf("%d", res);

	//int a = 5;
	//change_value(&a);
	//printf("value (a) = %d", a); // 7 expected



/*	int a = 4, b = 5;
	int res = get_mult(a, b);
	printf("Mult returned: %d", res); */

	return 0;
}