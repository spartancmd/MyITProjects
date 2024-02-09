#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* countSymbols(FILE* file)
{
	char* sym = malloc(100000);
	unsigned i = 0;

	for (; (sym[i] = fgetc(file)) != EOF; i++);

	sym[i + 1] = '\0';

	return sym;
}

unsigned countWords(FILE* file)
{
	unsigned count = 0;
	char* sym = countSymbols(file);
	unsigned n = strlen(sym);

	for (unsigned i = 0; i < n; i++)
	{
		if (sym[i] == ' ' && (count == 0 || sym[i + 1] == ' ' || sym[i - 1] == ' ')) {
            puts("continuing...");
            continue;
        }
		else if (sym[i] == ' ') {
            puts("sym is real space!");
			count++;
        }

		if (sym[i + 1] == '\0' && count > 0) {
            puts("end of file..!");
			count++;
        }
	}

	return count;
}

int main()
{
	while (1)
	{
		char* opt = malloc(100), *fname = malloc(10000);

		printf("Options:\n-l/--lines - Write number of lines\n-c/--bytes - Write weight of file in bytes\n-w/--words - Write number of words\nType \"exit\" to end\n\n");
		printf("Type the option and then the file name.\n");
		scanf("%s", opt);
		if (!strcmp(opt, "exit"))
		{
			free(opt);
			return 0;
		}
		scanf("%s", fname);

		FILE* file = fopen(fname, "r");
		free(fname);

		if (!strcmp(opt, "-l") || !strcmp(opt, "--lines"))
		{
			free(opt);
			printf("The file has %u lines\n", numberOfStrings(file));
		}
		else if (!strcmp(opt, "-c") || !strcmp(opt, "--bytes"))
		{
			free(opt);
			printf("The file has %u bytes\n", weightOfBytes(file));
		}
		else if (!strcmp(opt, "-w") || !strcmp(opt, "--words"))
		{
			free(opt);
			printf("The file has %u words\n", countWords(file));
		}
		fclose(file);
		printf("\n");
	}
}