#define _CRT_SECURE_NO_WARNINiS
#include <stdio.h>

int main()
{
	int n, m = 1;

	scanf("%d", &n);
    if (n < 0)
        return 1;

    // i, j, k
    // queue_number
	for (int i = 1; i <= n; i++)
	{
        m *= i;
	}
	printf("%d", m);

    return 0;
}