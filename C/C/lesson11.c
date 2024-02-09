#include <stdio.h>

int main() {
	int x = 258;
	// &, |
	// we are familiar with && and ||

	// >>, <<
	// << - умножает число на 2
	// >> - делит число на 2 нацело
	while (x > 0) {
		printf("%d\n", x & 1); // побитовая конъюнкция
		x = x >> 2;
	}
	//printf("%d", x & 1); // побитовая конъюнкция

	return 0;
}