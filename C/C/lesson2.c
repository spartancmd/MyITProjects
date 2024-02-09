#include <stdio.h>
#include <limits.h>

int main(void)
{
/*	int a = 9000;
	int b = 5;*/
	// *variable type* *variable name* = *initial value*;
	// int b = 5;

	// VARIABLE TYPES
	// int - integer number from approximately [-2.000.000.000 <-> 2.000.000.000]
	//										   (depends on particular computer)
	// unsigned int - [0 <-> 4.000.000.000]
	// char (from word "charater") - [-128 <-> 127]
	// float - (number with floating point) - decimal fractures
	// double - (number with floating point with double accuracy) - decimal fractures
	// short - (short number) - [-32768 <-> 32767]
	// long - long number from approximately [-2.000.000.000 <-> 2.000.000.000]

	// Type specialization (qualificators)
	// [*type qualicator*] *variable type* *var name* = *initial value*

	//// unsigned
	//unsigned int a = 4000000000;
	//printf("%u", a);

	// signed
	// signed int a = 0 <=> int a = 0; 

	//// long (do not mix up with type "long")
	//long long l = 1000000000000000;
	//long double d = 3132.144234323434;
	//printf("%lld\n", l);
	//printf("%Lf", d);
	
	//int a = 13;

	//// some code, which requires type of a = int
	//
	//float b = 10;
	//float c = (float)a / (float)b; 
	//int e = (int)c; // explicit type cast
	//int d = c; // implicit type cast

	//int x = 10000000;
	//short s = x;
	//printf("%d\n", s);

	//short s1 = 30000;
	//short s2 = 30000;
	//short res = s1 * s2; // type cast from short to int
	//printf("%d\n", res);

	//printf("%.1f\n\n", c);

	//// overflow
	//short s1 = 32767;
	//short s2 = 32767;
	//short s = s1 + s2;
	//printf("%d", s);

	//long l = 200000;
	//printf("%d", l);

	//// float
	//double f = 12345679.12345678901234;
	//printf("%.20f", f); // %f - output as a decimal fracture

	//char c = 'a';
	//printf("%c", c); // %c - output as a symbol

	// THE MOST POPULAR TYPES
	// int, float, double, char, long long, unsigned int

	double _d;
	unsigned short size = sizeof(_d);
	printf("%d\n", size);

	printf("INT MAX: %d\n", INT_MAX);
	printf("INT MIN: %d", INT_MIN);
	CHAR_MAX, CHAR_MIN, LONG_MAX, UINT_MAX;
	//int a = 1500000000;
	//int b = 1500000000;

	return 0;
}