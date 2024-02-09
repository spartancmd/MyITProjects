#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

struct drob
{
	int ches;
	int snam;
};

struct drob add(struct drob dr, struct drob dr2)
{
	if (dr.snam != dr2.snam)
	{
		int temp = dr.snam;
		dr.ches *= dr2.snam;
		dr.snam *= dr2.snam;
		dr2.ches *= temp;
		dr2.snam *= temp;
	}

	struct drob dres;
	dres.ches = dr.ches + dr2.ches;
	dres.snam = dr.snam;

	return dres;
}

struct drob sub(struct drob dr, struct drob dr2)
{
	if (dr.snam != dr2.snam)
	{
		int temp = dr.snam;
		dr.ches *= dr2.snam;
		dr.snam *= dr2.snam;
		dr2.ches *= temp;
		dr2.snam *= temp;
	}

	struct drob dres;
	dres.ches = dr.ches - dr2.ches;
	dres.snam = dr.snam;

	return dres;
}

struct drob mult(struct drob dr, struct drob dr2)
{
	struct drob dres;
	dres.ches = dr.ches * dr2.ches;
	dres.snam = dr.snam * dr2.snam;

	return dres;
}

struct drob div(struct drob dr, struct drob dr2)
{
	struct drob dres;
	dres.ches = dr.ches * dr2.snam;
	dres.snam = dr.snam * dr2.ches;

	return dres;
}

void print_result(struct drob fraction)
{
	printf("Result: \n%d\n--\n%d\n", fraction.ches, fraction.snam);
}

double printf_deznumber(struct drob dr)
{
	return (double)dr.ches / dr.snam;
}

int main()
{
	char a[20];
	struct drob dr, dr2;

	printf("Type the numerator and the denomerator of the first fraction.\n");
	if (0 == scanf("%d %d", &dr.ches, &dr.snam)) {
		printf("You typed not a number!\n");
		return 0;
	}
	if (dr.snam == 0)
		return 0;
	printf("Type the numerator and the denomerator of the second fraction.\n");
	if (0 == scanf("%d %d", &dr2.ches, &dr2.snam)) {
		printf("You typed not a number!\n");
		return 0;
	}
	if (dr2.snam == 0)
		return 0;

	while (1)
	{
		printf("Type the number for the operation\n(0: exit 1: + 2: - 3: * 4: / 5: Printf the dezimal number of the first fraction.)\n");
		if (0 == scanf("%s", a)) {
			printf("You typed not a number!\n");
			continue;
		}

		if (strcmp(a, "0") == 0) {
			return 0;
		}
		else if (strcmp(a, "1") == 0)
		{
			print_result(add(dr, dr2));
		}
		else if (strcmp(a, "2") == 0)
		{
			print_result(sub(dr, dr2));
		}
		else if (strcmp(a, "3") == 0)
		{
			print_result(mult(dr, dr2));
		}
		else if (strcmp(a, "4") == 0)
		{
			print_result(div(dr, dr2));
		}
		else if (strcmp(a, "5") == 0)
			printf("Result: %.5f\n", printf_deznumber(dr));
		else {
			printf("Unknown command!\n");
		}

		printf("\n");
	}
}