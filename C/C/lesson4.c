#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf('a');
	// output all numbers from zero to ...

	// for, while, [do while]
	int n = 5; // output all numbers from 0 to 100
	//scanf("%d", &n);

	int emergency_loop_exit = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k) 
			{
				printf("before break: (%d %d)\n", i, j);
				emergency_loop_exit = 1;
				break;
				printf("after break: (%d %d)\n", i, j);
			}
			if (emergency_loop_exit)
				break;
			printf("inside another loop\n");
		}
		if (emergency_loop_exit)
			break;
		printf("inside external loop\n");
	}

	//for (int i = 0; 
	//	 i < n;
	//	 i++)
	//{
	//	printf("iteration %d\n", i);
	//	if (i >= 10)
	//		//break; // "break" operator breaks loop execution
	//		break;
	//	printf("%d\n", i);
	//}
	
	//for (int i = 1;; i += 1) // for (init; condition; increment)
	//{
	//	printf("%d\n", i);
	//}

	//int i = 0;
	//while (i <= n)
	//{ // loop body
	//	printf("%d\n", i);
	//	i *= 2; // decrementation (incrementation)
	//}

	return 0;
}