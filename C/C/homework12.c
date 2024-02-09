#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fstrcpy(char* dst, char* src)
{
	int i = 0;
	for (; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
}

int main()
{
	char* dst = malloc(1000);
	char* src = malloc(1000);

	printf("Print the first text.\n");
	scanf("%s", src);

	fstrcpy(dst, src);

	printf("Result dst:\n%s", dst);

	return 0;
}

//int fstrlen(char* string)
//{
//	int result = 0;
//
//	for (int i = 0; *(string + i) != '\0'; i++)
//		result++;
//
//	return result;
//}
//
//char fstrcmp(char* str1, char* str2)
//{
//	int count1 = fstrlen(str1), count2 = fstrlen(str2), count = 0;
//
//	if (count1 < count2)
//		count = count2;
//	else if (count1 > count2)
//		count = count1;
//	else
//		count = count1;
//
//	for (int i = 0; i < count; i++)
//	{
//		if (*(str1 + i) == *(str2 + i)) continue;
//		else if (*(str1 + i) != *(str2 + i))
//		{
//			if (*(str1 + i) > * (str2 + i))
//				return 1;
//			else
//				return -1;
//		}
//		else break;
//	}
//
//	return 0;
//}
//
//int main()
//{
//	char* str1 = malloc(1000);
//	char* str2 = malloc(1000);
//	while (1)
//	{
//		printf("Print the first text.\n");
//		scanf("%s", str1);
//		printf("Print the second text.\n");
//		scanf("%s", str2);
//
//		char res = fstrcmp(str1, str2);
//
//		if (res == 0)
//			printf("\nThe strings are same.\n\n\n\n");
//		else
//			printf("\nThe strings aren't same.\n\n\n\n");
//	}
//}

//int fstrlen(char const * string)
//{
//  string = NULL; // OK
//  string[0] = 0; // will not compile
//	int result = 0;
//
//	while (*(string + result) != '\0')
//		result++;
//
//	return result;
//}
//
//int main()
//{
//	char* string = (char*)malloc(1000000);
//
//	printf("Print text.\n");
//	//scanf("%s", string);
//	fgets(string, 100000, stdin);
//
//	printf("Result: %d\n", fstrlen(string));
//
//	// you must free memory
//	free(string);
//
//	return 0;
//}