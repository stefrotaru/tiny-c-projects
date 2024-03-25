#include <wchar.h> // 1

int main() {
    wprintf(L"Hello, wide World!\n"); // 2

    return 0;
}

// 1. Wide character definitions and functions
// 2. The wprinf() function is analogous to printf() but for wide characters.
// The L prefix is required for a string composed of wide characters.