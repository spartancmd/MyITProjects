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


int searchElementsM(char* fname, Elements* PSE, int n)
{
	for (unsigned i = 0; i < n; i++)
	{
		if (!strcmp(fname, PSE[i].symb))
			return PSE[i].M;
	}
}

void calcAmountOfFabrics(Elements* PSE, int length)
{
	int M = 0, val;
	double res = 0, tempres = 0, tempres2 = 0, m = 0;
	char* elmsym = malloc(100);

	printf("Bitte die Masse m in gramm eingeben.\n");
	scanf("%lf", &m); 

	for (unsigned i = 0; 1; i++)
	{
		printf("Wenn alle Elemente eingegeben sind, \"fertig\" eingeben.\nBitte das Symbol des %d. Elements und danach seinen Koeffizient getrenntvoneinander eingeben. (wenn es keinen Koeffizient gibt, dann 1 eingeben)\n", i + 1);
		scanf("%s", elmsym);  

		if (!strcmp(elmsym, "fertig")) break;
			
		scanf("%d", &val);

		M = searchElementsM(elmsym, PSE, length); 

		tempres = (double) M * val; 
		tempres2 += tempres;
	}

	res = m / tempres2; 
	printf("\nn = %.16lf mol\n", res);

	free(elmsym);
}



void calcMass(Elements* PSE, int length)
{
	int M, val;
	double n = 0, res = 0, tempres = 0, tempres2 = 0, m = 0;
	char* elmsym = malloc(100);

	printf("Bitte die Stoffmenge \"n\" eingeben.\n");
	scanf("%lf", &n);

	for (unsigned i = 0; 1; i++)
	{

		printf("Wenn alle Elemente eingegeben sind, \"fertig\" eingeben.\nBitte das Symbol des %d. Elements und danach seinen Koeffizient getrenntvoneinander eingeben. (Wenn es keinen Koeffizient gibt, dann stattdessen 1 eingeben)\n", i + 1);
		scanf("%s", elmsym); 

		if (!strcmp(elmsym, "fertig")) break;

		scanf("%d", &val); 

		M = searchElementsM(elmsym, PSE, length); 

		tempres = (double)M * val;
		tempres2 += tempres;
	}

	res = n * tempres2;
	printf("\nm = %.16lf g\n", res);

	free(elmsym);
}

int loadPSE(Elements* element)
{
	int count = 0;
	FILE* file = fopen("PSE.txt", "r"); 

	while (fgetc(file) != '\n'); 

	for (int i = 0; !feof(file); i++, count++) 
		fscanf(file, "%s %s %d %d\n", element[i].symb, element[i].name, &(element[i].pos), &(element[i].M));

	fclose(file);

	return count;
}

void list(Elements* element, int n)
{
	printf("      Symbol  \t  Name\t        Position     molare Masse (g/mol)\n\n");
	for (int i = 0; i < n; i++)
		printf("\t%s  \t%-16s   %-3d\t\t%-5d\n", element[i].symb, element[i].name, element[i].pos, element[i].M);
}

void typeFormulas()
{
	printf("n - Stoffmenge\tm - Masse\tM - molare Masse\n\n");

	printf("    m\nn = -\n    M\n\n");
	printf("m = n * M");
}

int main()
{
	Elements* elements = malloc(sizeof(Elements) * 1000);
	char* order = malloc(100);
	int length = loadPSE(elements);

	printf("Taschenrechner fuer Chemie, um Stoffmenge oder Masse auszurechnen\nMit freundlichen Gruessen von Deniel :)\nVerwendete Programmiersprache: C\n\n");

	while (1)
	{
		char* order = malloc(100);

		printf("Um die Tabelle mit den Elementen anzuzeigen \"liste\" eingeben.\nUm die Formeln anzuzeigen \"formeln\" eingeben.\nUm die Programm zu beenden \"beenden\" eingeben.\nUm die Stoffmenge auszurechnen \"n\" eingeben.\nUm die Masse auzurechnen \"m\" eingeben.\n\n");
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
		else if (!strcmp(order, "formeln"))
		{
			free(order);
			typeFormulas();
		}
		else if (!strcmp(order, "liste"))
		{
			free(order);
			list(elements, length);
		}
		else if (!strcmp(order, "beenden"))
		{
			free(order);
			break;
		}

		printf("\n");
	}

	free(elements);

	return 0;
}