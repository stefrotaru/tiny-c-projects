#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main() {
	const wchar_t alpha = 0x391;
	const wchar_t omega = 0x3a9;
	const wchar_t no_sigma = 0x3a2;
	const char *file = "alphabeta.wtxt";
	FILE *fp;
	wchar_t a;

	fp = fopen(file, "w");
	if( file==NULL )
	{
		fprintf(stderr, "Unable to open %s\n", file);
		exit(1);
	}
	
	setlocale(LC_CTYPE, "en_US.UTF-8");

	wprintf(L"Writing the Greek alphabet...\n"); // 1
	for( a=alpha; a<=omega; a++ ) { // 2
		if( a==no_sigma ) // 3
			continue; // 4
		fputwc(a, fp); // 5
		fputwc(a, stdout); // 6
	}
	fputwc('\0', fp); // 7

	fclose(fp);
	wprintf(L"\nDone\n");

	return 0;
}

// 1. Lets the user know what's going on
// 2. Loops through the Greek alphabet
// 3. Tests for the blank sport and ...
// 4. ... skips over this noncharacter, continuing the loop
// 5. Writes the Greek letter to the file (FILE pointer fp)
// 6. Also sends a null character to the file so that wide string file input functions can be used to read it in later
// 7. Writes a null character to the file so that wide string file input functions
// can be used to read it in later