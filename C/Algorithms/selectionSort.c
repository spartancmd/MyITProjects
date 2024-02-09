#include <stdio.h>

// returns index of minimal element in array a
// unsigned minIndex(int* a, unsigned n) {
//     int mn = a[0];
//     int minIdx = 0;
//     for (unsigned i = 1; i < n; i++) {
//         if (a[i] < mn) {
//             mn = a[i];
//             minIdx = i;
//         }
//     }

//     return minIdx;
// }

// void swap(int* el1, int* el2) {
//     int tmp = *el1;
//     *el1 = *el2;
//     *el2 = tmp;
// }

// void selectionSort(int* a, unsigned n) {
//     if (n == 0 || a == NULL)
//         return;

//     for (unsigned i = 0; i < n; i++) {
//         unsigned idx = minIndex(a + i, n - i);
//         swap(a + idx + i, a + i);
//     }
// }

// void printArray(int* a, unsigned n) {
//     for (unsigned i = 0; i < n; i++)
//         printf("%d ", a[i]);
//     printf("\n");
// }

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int* m, unsigned n)
{
    if (n == 0 || m == NULL)
        return;

	int* min = m;
	for (unsigned i = 0; i < n; i++)
	{
        min = m + i;
		for (unsigned j = i; j < n; j++)
		{
			if (*min > m[j])
				min = m + j;
		}

        swap(m + i, min);
	}
}

int main()
{
	int massive[] = { 2, 1, 5, 3, 8, 9, 6, 10, 7, 4 };
	unsigned lenght = 10;

	printf("Before SelectionSort:\n");
	for (unsigned i = 0; i < 10; i++) // Вывод элементов массива до сортировки
		printf("[%d] = %d\n", i, massive[i]);
	printf("\n\n");

	selectionSort(massive, lenght); //вызов функции для сортировки (по возврастанию)

	printf("After SelectionSort:\n");
	for (unsigned i = 0; i < 10; i++) // Вывод элементов массива после сортировки
		printf("[%d] = %d\n", i, massive[i]);

	return 0;
}