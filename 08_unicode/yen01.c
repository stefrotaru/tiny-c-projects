#include <wchar.h>
#include <locale.h>

int main() {
	wchar_t yen = 0xa5; // 1

	setlocale(LC_CTYPE, "en_US.UTF-8");

	wprintf(L"That will be %lc500\n", yen); // 2

	return(0);
}

// 1. The character is specified by its Unicode value, U-00A5
// 2. The %lc placeholder represents the wide character value in yen