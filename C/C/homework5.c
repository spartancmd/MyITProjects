#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int c5 = 0, c4 = 0, i = 0, x;
	unsigned int t = 257;
	unsigned int* ptr = &t;
	unsigned char* bytes = ptr;
	printf("%d %d %d %d", bytes[0], bytes[1], bytes[2], bytes[3]);
	return 0;

	while (1)
	{
		if (i == 0)
		{
			scanf("%d", &x);
			if (x == 0) break;
			else if (x == 5)
				c5 = 1;
			else if (x == 4)
				c4 = 1;
		}
		else
		{
			scanf("%d", &x);
			if (x == 0) break;
			else if (x == 5)
				c5++;
			else if (x == 4)
				c4++;
		}
		i++;
	}
	printf("%d %d", c5, c4);

	return 0;
}

//int main()
//{
//	int alphabet[] = { 'A', 'B', 'C','D','E','F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//	
//	// твоя строка
//	//for (int i = 0; i <= 26; i++)
//	// исправленная:
//	for (int i = 0; i < 26; i++)
//	{
//		// твоя строка:
//		//printf("%s ", alphabet[i]);
//		// исправленная:
//		printf("%c ", alphabet[i]);
//		// Ошибка в том, что есть разница между словами
//		// "строка" и "символ"
//		// Символ заключен в одинарные кавычки, 
//		// строка - в двойные. Для вывода символа исплльзуется
//		// %c, для вывода строки - %s
//	}
//
//	return 0;
//	int x, cnt = 0;
//	scanf("%d", &x); // natural number greater than 1
//
//	// number is simple if it has exactly two dividers
//	int min = 1, max = sqrt(x);
//
//	// 1   n   n^2  - dividers of n^2 (n is prime)
//	for (int i = min + 1; i <= max; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("YES");
//			return 0;
//		}
//	}
//
//	printf("NO");
//}

//int main()
//{
//	int x, min = -1;
//
//	while (1)
//	{
//		scanf("%d", &x);
//
//		if (x == 0)
//			break;
//		else if (x < 0)
//			continue;
//
//		if (min == -1 || x < min)
//			min = x;
//	}
//
//	if (min == -1)
//		printf("There were no positive number in flow!");
//	else
//		printf("%d", min);
//
//	return 0;
//}