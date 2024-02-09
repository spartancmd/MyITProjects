#include <stdio.h>
#include <limits.h>

int main()
{
	// sizeof(int) = 4 bytes (32 bits)
	//unsigned int* part1 = (unsigned int*)malloc(sizeof(int));
	//*part1 = 0;

	//unsigned int* part2 = part1 + 1;

	//unsigned long long* ptr = part1;

	//*ptr = 16 * ((long long)UINT_MAX + 1); //  ((long long)UINT_MAX + 1); // ULLONG_MAX;

	//printf("part 1: %u, part2: %u", *part1, *part2);

	//unsigned int a = (long long)256 * 256 * 256 * 256 - 1; // 10 в 256-ричной системе счисления
	int a = -1;

	unsigned char* a1 = &a; // sizeof(unsigned char) = 1
	unsigned char* a2 = a1 + 1;
	unsigned char* a3 = a1 + 2;
	unsigned char* a4 = a1 + 3;
	printf("a1: %u, a2: %u, a3: %u, a4: %u\n", *a1, *a2, *a3, *a4);
}