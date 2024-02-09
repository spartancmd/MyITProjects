#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, cnt = 0;
	long long a = 20000000000;
	printf("%lld", a);

	return 0;
	long long l = 10000000000;
	printf("%lld", l);

	return 0;

	x = l;
	printf("%d", x);
	
	return 0;

	scanf("%d", &x);

	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
			cnt++;
	}
	printf("%d", cnt);
}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//		printf("%d ", i);
//
//	for (int j = n - 1; j >= 1; j--)
//		printf("%d ", j);
//}

//
//int main()
//{
//	// given n and m - table sizes
//
//	// Sample:
//	// 3 2
//	// 100 100
//	// 100 100
//	// 200 200
//	// Output a sum of all table elements
//	// Sample answer: 800
//
//	int n, m, sum = 0;
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			int x;
//			scanf("%d", &x);
//			sum += x;
//		}
//	}
//	printf("%d", sum);
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; ++i)
//	{
//		// print all numbers from 1 to i in one line
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d ", j);
//		}
//
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int n, sum = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//
//	printf("%d", sum);
//	return 0;
//}

//#include <math.h>
//
//int main()
//{
//	for (int a = 10; a * a < 1000; a++)
//	{
//		printf("%d\n", a);
//	}
//}

//int main()
//{
//	int n, c, div = 2;
//	int even = 0, odd = 0;
//	scanf("%d", &n);
//	
//	for (int b = 0; b < n; b++)
//	{
//		scanf("%d", &c);
//	
//		if (c % div == 0)
//			even++;
//		else
//			odd++;
//	}
//	printf("Even: %d, odd: %d", even, odd);
//}

// 3

//int main()
//{
//	int x, sum = 0;
//	scanf("%d", &x);
//
//	while (x != 0)
//	{
//		sum += x;
//		scanf("%d", &x);
//	}
//
//	printf("%d", sum);
//	return 0;
//}


// 2
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main()
//{
//	int n;
//	int sum = 0;
//	int c;
//
//	// sum += 5;
//	// same that sum = sum + 5
//
//	scanf("%d", &n);
//
//	for (int b = 0; b < n; b++)
//	{
//		scanf("%d", &c);
//
//		sum += c;
//	}
//	printf("%d", sum);
//}