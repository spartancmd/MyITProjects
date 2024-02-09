#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void testGetCountOfWords();
void testTransform();

unsigned numberOfStrings(FILE* file)
{
	unsigned count = 1;
	char buffer = 0;

	while ((buffer = fgetc(file)) != EOF)
	{
		if (buffer == '\n')
			count++;
	}

	return count;
}

unsigned weightOfBytes(FILE* file)
{
	unsigned bytes = 0;

	while (fgetc(file) != EOF)
		bytes++;

	return bytes;
}

char* increaseMemory(char* oldMemory, int* bytes)
{
	char* newMemory = malloc(*bytes * 2);

	if (newMemory == NULL)
	{
		printf("Error: Allocation failed\n");
	}

	for (unsigned i = 0; i < *bytes; i++)
		newMemory[i] = oldMemory[i];

	(*bytes) *= 2;

	free(oldMemory);

	return newMemory;
}

char* readInToBuffer(FILE* file)
{
	int* bytes = malloc(sizeof(int));
	(*bytes) = 16;
	char* sym = malloc(*bytes + 1);
	unsigned i = 0;

	if (sym == NULL || bytes == NULL)
	{
		printf("Error: Allocation failed\n");

		return NULL;
	}

	for (; i <= (*bytes); i++)
	{
		printf("Current bytes val is: %d, current i is: %d\n", *bytes, i);
		sym[i] = fgetc(file);
		if (sym[i] == EOF) break;
		else if (i == *bytes)
			sym = increaseMemory(sym, bytes);
	}

	sym[i] = '\0';

	free(bytes);

	return sym;
}

char* transform(char* sym)
{
	unsigned n = strlen(sym);

	for (unsigned j = 0; j < n; j++)
	{
		if (sym[j] != ' ' && sym[j] != '\t' && sym[j] != '\n')
			sym[j] = '1';
		else
			sym[j] = '0';
	}

	return sym;
}

unsigned getCountOfWords(char* sym)
{
	unsigned count = 0, n = strlen(sym);

	for (unsigned i = 0; i <= n; i++)
	{
		if (i > 0)
		{
			if (sym[i] == '0' && sym[i - 1] != '0')
				count++;

			if (sym[i] == '\0' && sym[i - 1] != '0')
				count++;
		}
		else
			if (sym[i] == '1' && n <= 2)
			{
				count++;
				break;
			}
	}

	return count;
}

unsigned countWords(FILE* file)
{
	char* sym = readInToBuffer(file);
	sym = transform(sym);
	unsigned count = getCountOfWords(sym);

	free(sym);
	return count;
}

char redirectProcess(char* opt, FILE* file)
{
	if (!strcmp(opt, "-l") || !strcmp(opt, "--lines"))
		printf("The file has %u lines\n", numberOfStrings(file));
	else if (!strcmp(opt, "-c") || !strcmp(opt, "--bytes"))
		printf("The file weights %u bytes\n", weightOfBytes(file));
	else if (!strcmp(opt, "-w") || !strcmp(opt, "--words"))
		printf("The file has %u words\n", countWords(file));
	else
		return 1;

	return 0;
}

int main(int argc, char* argv[])
{
	testTransform();
	testGetCountOfWords();

	if (argc == 3)
	{
		FILE* file = fopen(argv[2], "r");

		if (file == NULL)
		{
			perror("Error when opening the file");

			return 1;
		}

		if (redirectProcess(argv[1], file))
		{
			printf("No such option!\n\n");
			printf("Options:\n-l/--lines - Writes number of lines\n-c/--bytes - Writes weight of file in bytes\n-w/--words - Writes number of words\n\n");
			printf("Type the option first after the programm name and then the file name.\n");

			return 0;
		}
	}
	else if (argc > 1)
	{
		printf("Not enough arguments printed!\n");
		printf("Options:\n-l/--lines - Writes number of lines\n-c/--bytes - Writes weight of file in bytes\n-w/--words - Writes number of words\n\n");
		printf("Type the option first after the programm name and then the file name.\n");

		return 0;
	}

	exit(0);

	while (1)
	{
		char* opt = malloc(10), *fname = malloc(10000);

		printf("Options:\n-l/--lines - Writes number of lines\n-c/--bytes - Writes weight of file in bytes\n-w/--words - Writes number of words\nType \"exit\" to end\n\n");
		printf("Type the option and then the file name.\n");
		scanf("%s", opt);

		if (!strcmp(opt, "exit"))
		{
			free(opt);
			return 0;
		}

		scanf("%s", fname);

		FILE* file = fopen(fname, "r");

		if (file == NULL)
		{
			perror("Error when opening the file");
			printf("\n\n");
			continue;
		}

		free(fname);

		if (redirectProcess(opt, file))
		{
			printf("No such option!\n\n");
			continue;
		}

		free(opt);
		fclose(file);

		printf("\n");
	}
}

void testGetCountOfWords()
{
	assert(getCountOfWords("011011110") == 2);
	assert(getCountOfWords("11011111001110") == 3);
	assert(getCountOfWords("0001111100111") == 2);
}

void testTransform()
{
	char* buffer = malloc(1000);

	if (buffer == NULL)
		printf("Testcase: Allocation error for buffer\n");

	strcpy(buffer, "  Mama	Papa	Brother	");
	assert(!strcmp(transform(buffer), "00111101111011111110"));
	strcpy(buffer, "Aaaaa Aaaaa Aaaa	aaaaaa");
	assert(!strcmp(transform(buffer), "11111011111011110111111"));
	strcpy(buffer, "	 Dragon  ooo cafe");
	assert(!strcmp(transform(buffer), "001111110011101111"));

	free(buffer);
}