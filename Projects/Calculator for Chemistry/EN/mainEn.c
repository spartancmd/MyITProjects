#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elements 
{
	int pos;
	int M;
	char name[100];
	char symb[100];
};

typedef struct Elements Elements;


int searchElementsM(char* elmSym, Elements* PSE, int n)	
{
	for (unsigned i = 0; i < n; i++)
	{
		if (!strcmp(elmSym, PSE[i].symb))
			return PSE[i].M;
	}
}

void calcAmountOfFabrics(Elements* PSE, int length) 
{
	int M = 0, val;
	double res = 0, tempres = 0, tempres2 = 0, m = 0;
	char* elmSym = malloc(100);

	printf("Please type the mass m in gramm.\n");
	scanf("%lf", &m); 

	for (unsigned i = 0; 1; i++)
	{
		printf("When all elements are typed, type \"finish\".\nPlease type the symbol of the %d. element and after his coefficient seperately from each other. (If there is no coefficient, type 1)\n", i + 1);
		scanf("%s", elmSym);  

		if (!strcmp(elmSym, "finish")) break;

		scanf("%d", &val); 

		M = searchElementsM(elmSym, PSE, length); 

		tempres = (double)M * val;
		tempres2 += tempres;
	}

	res = m / tempres2; 
	printf("\nn = %.16lf mol\n", res);

	free(elmSym);
}



void calcMass(Elements* PSE, int length) 
{
	int M, val;
	double n = 0, res = 0, tempres = 0, tempres2 = 0, m = 0;
	char* elmSym = malloc(100);

	printf("Please type the amount of fabric \"n\".\n");
	scanf("%lf", &n);

	for (unsigned i = 0; 1; i++)
	{
		printf("When all elements are typed, type \"finish\".\nPlease type the symbol of the %d. element and after his coefficient seperately from each other. (If there is no coefficient, type 1)\n", i + 1);
		scanf("%s", elmSym);  

		if (!strcmp(elmSym, "finish")) break;

		scanf("%d", &val); 

		M = searchElementsM(elmSym, PSE, length); 

		tempres = (double)M * val;
		tempres2 += tempres;
	}

	res = n * tempres2;
	printf("\nm = %.16lf g\n", res);

	free(elmSym);
}

int loadPSE(Elements* element)
{
	FILE* file = fopen("PSE.txt", "r"); 
	int count = 0;

	while (fgetc(file) != '\n'); 

	for (int i = 0; !feof(file); i++, count++) 
		fscanf(file, "%s %s %d %d\n", element[i].symb, element[i].name, &(element[i].pos), &(element[i].M));

	fclose(file);

	return count;
}

void list(Elements* element, int n)
{
	printf("      Symbol  \t  Name\t        Position     Molar mass (g/mol)\n\n");
	for (int i = 0; i < n; i++)
		printf("\t%s  \t%-16s   %-3d\t\t%-5d\n", element[i].symb, element[i].name, element[i].pos, element[i].M);
}

void typeFormulas()
{
	printf("n - amount of fabrics\tm - mass\tM - molar mass\n\n");
	
	printf("    m\nn = -\n    M\n\n");
	printf("m = n * M");
}

int main()
{
	Elements* elements = malloc(sizeof(Elements) * 1000);
	char* order = malloc(100);
	int length = loadPSE(elements);

	printf("Calculator for chemistry to calculate the amount of fabric and mass.\n\n");

	while (1)
	{
		char* order = malloc(100);

		printf("To show the list of elements type \"list\"\nTo exit the programm type \"exit\".\nTo print formulas type \"formulas\"\nTo calculate the amount of fabric type \"n\".\nTo calculate the mass type \"m\".\n\n");
		scanf("%s", order);
		printf("\n");

		if (!strcmp(order, "n")) 
		{
			free(order);
			calcAmountOfFabrics(elements, length);
		}
		else if (!strcmp(order, "m")) 
		{
			free(order);
			calcMass(elements, length);
		}
		else if (!strcmp(order, "formulas"))
		{
			free(order);
			typeFormulas();
		}
		else if (!strcmp(order, "list")) 
		{
			free(order);
			list(elements, length);
		}
		else if (!strcmp(order, "exit")) 
		{
			free(order);
			break;
		}

		printf("\n\n");
	}
	
	free(elements);

	return 0;
}