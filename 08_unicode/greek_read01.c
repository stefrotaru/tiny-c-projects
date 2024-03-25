#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main() {
	const char *file = "alphabeta.wtxt"; // 1
	const int length = 64; // 2
	FILE *fp;
	wchar_t line[length]; // 3

	fp = fopen(file, "r"); // 4
	if( file==NULL ) // 5
	{
		fprintf(stderr, "Unable to open %s\n", file);
		exit(1);
	}
	
	setlocale(LC_CTYPE, "en_US.UTF-8");

	wprintf(L"Reading from %s:\n", file); // 6
	fgetws(line,length, fp); // 7
	wprintf(L"%ls\n", line); // 8

	fclose(fp);

	return 0;
}

// 1. The file to open
// 2. Defines a constant for the input buffer
// 3. The wide character input buffer
// 4. Opens the file for reading
// 5. Handles any errors
// 6. Lets the user know what's going on
// 7. Reads a line of text from the file (up to the null character)
// 8. Outputs the line read