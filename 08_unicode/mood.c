#include <locale.h>
#include <wchar.h>

int main() {
	wchar_t mood; // 1

	setlocale(LC_CTYPE, "en_US.UTF-8");

	wprintf(L"What is your mood? "); // 2
	mood = getwchar(); // 3
	wprintf(L"I feel %lc, too!\n", mood); // 4

	return 0;
}

// 1. The single wide character variable mood holds input
// 2. This string is ASCII, but the L prefix makes it composed of wide characters
// 3. Obtains a wide character from standard input and storoes it in wcar_t
// variable mood
// 4. The %lc placeholder represents wide character mood