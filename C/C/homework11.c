#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <Windows.h>

//Необходимо реализовать структуры точки (две вещественные (double) координаты), отрезка (две точки)
//Реализовать функцию получения длины отрезка, который передается на вход по указателю(ВАЖНО, именно по указателю - особого смысла в этом нет, но ты сможешь потренироваться в умении правильно обращаться к полям вложенных структур)
//Спойлер: структуры нужно вложить друг в друга, то есть отрезок будет иметь в себе две точки
//К этому нужно написать тесты - создать отрезок, проверить, что его длина действительно правильная
//Тесты нужно реализовать с помощью функции assert

struct Point
{
	double x, y;
};

struct Segment
{
	struct Point p1;
	struct Point p2;
};

double absolute(double x)  // returns absolute value of given number
{
	if (x > 0)
		return x;
	else
		return -x;
}

void get_length(struct Segment* s, double* res)
{
	double x1, x2, y1, y2;

	x1 = s->p1.x;
	y1 = s->p1.y;

	x2 = s->p2.x;
	y2 = s->p2.y;

	double a, b;

	// init a, b
	a = x1 - x2;
	b = y1 - y2;

	if (x1 > x2)
		a = x1 - x2;
	else
		a = x2 - x1;

	/*if (y1 > y2)
		b = y1 - y2;
	else
		b = y2 - y1;*/
	//b = absolute(y1 - y2);

	*res = sqrt(a * a + b * b);
	return;

	//if (y1 == y2)
	//{
	//	if (x1 >= 0 && x2 >= 0)
	//	{
	//		if (x1 > x2)
	//			*res = x1 - x2;
	//		else if (x1 < x2)
	//			*res = x2 - x1;
	//	}
	//}
	//else
	//{
	//	if (x1 >= 0 && x2 >= 0)
	//	{
	//		if (x1 > x2)
	//			*res = sqrt(x1 * x1 - x2 * x2);
	//		else if (x1 < x2)
	//			*res = sqrt(x2 * x2 - x1 * x1);
	//	}
	//}
}

// We need tests for the next reasons:
// 1) Checking if our program works properly
// 2) Fix the behaviour

void test_segment_length()
{
	struct Segment segment;
	double result;
	segment.p1.x = 0;
	segment.p1.y = 0;
	segment.p2.x = 1;
	segment.p2.y = 1;
	get_length(&segment, &result);
	assert(result  == sqrt(2));

	segment.p1.x = -1; // set up
	segment.p1.y = 1;
	segment.p2.x = 1;
	segment.p2.y = -1;
	get_length(&segment, &result); // executing
	assert(result == 2 * sqrt(2)); // assertion

	segment.p1.x = 0;
	segment.p1.y = 0;
	segment.p2.x = 0;
	segment.p2.y = 0;
	get_length(&segment, &result);
	assert(result == 0);

	printf("Tests are passed!");
}

int main()
{
	double result;
	struct Segment segment;

	clock_t begin_time = clock(); // number of seconds since 1970
	/*while (clock() - begin_time < 10) {
		printf("Waiting...");
	}*/
	printf("We will sleep for 5 sec");
	Sleep(5000);

	printf("Now are able to call function f");
	return 0;

	test_segment_length();

	//printf("Type the koordinate x and y of first point!\n");
	//scanf("%lf %lf", &segment.p1.x, &segment.p1.y);
	//printf("Type the koordinate of x anf of second point!\n");
	//scanf("%lf %lf", &segment.p2.x, &segment.p2.y);

	//get_length(&segment, &result);
	//assert(result >= 0);

	//printf("Result: %f", result);
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <limits.h>
//
////Написать функцию, которая будет возвращать по числу x его бит номер n в следующих вариациях:
////1) Биты нумеруются справа - налево
////2) Биты нумеруются слева - направо
//
//
//int function1(int x, int n)
//{
//	return (x >> n) & 1;
//}
//
//int function2(int x, int n, int size)
//{
//	return (x >> (8 * size - (n + 1))) & 1;
//}
//
//int main()
//{
//	int x;
//	x = -2;
//	char* byte1 = &x;
//	char* byte2 = byte1 + 1;
//	char* byte3 = byte1 + 2;
//	char* byte4 = byte1 + 3;
//	for (int i = 0; i < sizeof(char) * 8; i++)
//		printf("%d ", function2(*byte1, i, 1));
//	printf("\n");
//
//	for (int i = 0; i < sizeof(char) * 8; i++)
//		printf("%d ", function2(*byte2, i, 1));
//	printf("\n");
//
//	for (int i = 0; i < sizeof(char) * 8; i++)
//		printf("%d ", function2(*byte3, i, 1));
//	printf("\n");
//
//	for (int i = 0; i < sizeof(char) * 8; i++)
//		printf("%d ", function2(*byte4, i, 1));
//	printf("\n");
//
//	printf("Must be:\n");
//
//	for (int i = 0; i < 32; i++)
//		printf("%d ", function2(x, i, 4));
//
//	//printf("Type x and n.\n");
//	//while (1)
//	//{
//	//	//scanf("%d %d", &x, &n);
//	//	x = -1;
//
//	//	printf("When numbered from right to left: %d\nWhen numbered from left to right: %d\n", function1(x, n), function2(x, n));
//	//}
//}