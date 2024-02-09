#include <stdio.h>
#include <limits.h>

int main()
{
	int x = INT_MIN;  // 4 bytes

	unsigned char* byte1;
	unsigned char* byte2;
	unsigned char* byte3;
	unsigned char* byte4;

	byte1 = &x;
	byte2 = byte1 + 1;
	byte3 = byte1 + 2;
	byte4 = byte1 + 3;

	printf("1: %u, 2: %u, 3: %u, 4: %u", *byte1, *byte2, *byte3, *byte4);
	return 0;
}