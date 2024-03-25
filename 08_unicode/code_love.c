#include <wchar.h>
#include <locale.h>

int main() {
	wchar_t s[] = L"I * to code\n";

	setlocale(LC_ALL, "en_US.UTF-8");

    // replace the * with a heart
	s[2] = 0x2665;
	fputws(s, stdout);

	return 0;
}