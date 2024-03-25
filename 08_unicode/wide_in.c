#include <stdio.h> // 1
#include <wchar.h>
#include <locale.h>

int main() {
    const int size = 32; // 2
    wchar_t input[size]; // 3

    setlocale(LC_CTYPE, "UTF-8");

    wprintf(L"Type some fancy text: ");
    fgetws(input, size, stdin); // 4
    wprintf(L"You typed: %ls", input); // 5

    return 0;
}

// 1. Required for the definition of stdin
// 2. Uses a constant to set the buffer size
// 3. Wide character input buffer
// 4. Reads the size characters into the input buffer from standard input
// 5. Uses the %ls placeholder to output the wide character string