#include <wchar.h>
#include <locale.h>

int main() {
    const int count = 4;
    wchar_t suits[] = {
        0x2660, 0x2665, 0x2666, 0x2663 // 1
    };
    int x;

    setlocale(LC_CTYPE, "en_US.utf-8"); // 2

    for ( x = 0; x < count; x++ )
        putwchar(suits[x]); // 3
    putwchar('\n');

    return 0;
}

// 1. Unicode values for the four playing card suits
// 2. The locale is set because there are not ASCII characters
// 3. The puwchar() function outputs each wide character value