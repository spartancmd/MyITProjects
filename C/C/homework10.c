#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Задание 2: Необходимо отредактировать файл с числами, каждое из которых записано на своей строке
// В файле необходимо оставить только четные числа

int main()
{
	FILE* file = fopen("Numbers.txt", "r");
	int result[100], i = 0;

	if (file == NULL)
	{
		perror("Error");
		return 1;
	}

	while (!feof(file))
	{
		int a;
		fscanf(file, "%d\n", &a);
		
		if (a % 2 == 0)
		{
			result[i] = a;
			i++;
		}
	}
	fclose(file);
	
	if (i == 0)
	{
		printf("No numbers found.");
		return 1;
	}

	file = fopen("Numbers.txt", "w");
	printf("Printed numbers:\n");
	for (int ia = 0; ia < i; ia++)
	{
		fprintf(file, "%d\n", result[ia]);
		printf("%d ", result[ia]);
	}

	fclose(file);
	return 0;
}

//void f() {
//	int* a = malloc(sizeof(int) * 100);
//}
//
//int main()
//{
//	int n = 100;
//	int* memory = (int*)malloc(sizeof(int) * n); // heap
//
//	FILE* file = fopen("input.txt", "r");
//	if (file == NULL)
//	{
//		perror("Error while opening file 'input.txt'");
//		return 1;
//	}
//	if (feof(file)) {
//		printf("File 'input.txt' is empty!");
//		return 0;
//	}
//
//	int i = 0;
//	for (; !feof(file); i++) {
//		if (i == n) {
//			//memory = realloc(memory, n * 2);
//			int* new_memory = (int*)malloc(sizeof(int) * n * 2);
//			if (new_memory == NULL) {
//				// unable to allocate such a number of bytes
//			}
//			memcpy(new_memory, memory, n * sizeof(int));
//			free(memory);
//			memory = new_memory;
//
//			n *= 2;
//		}
//
//		fscanf(file, "%d", memory + i);
//	}
//	// всё до i-го элемента включительно заполнено
//	// 
//
//	int result[2] = { 0, 0 }, sum = 0;
//	for (int ib = 0; ib < i; ib++)
//	{
//		if (sum < (memory[ib] + memory[ib + 1]))
//		{
//			sum = memory[ib] + memory[ib + 1];
//			result[0] = memory[ib];
//			result[1] = memory[ib + 1];
//		}
//	}
//	fclose(file);
//	free(memory);
//
//	FILE* file_result = fopen("out.txt", "w");
//
//	fprintf(file_result, "%d %d", result[0], result[1]);
//	printf("Result is printed.\nFirst number: %d\nSecond number: %d\n", result[0], result[1]);
//	fclose(file_result);
//
//	return 0;
//}