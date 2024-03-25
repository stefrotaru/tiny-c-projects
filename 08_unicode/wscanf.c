#include <wchar.h>
#include <locale.h>

int main() {
    const wchar_t pound = 0xa3; // 1
    int quantity;
    float total;

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"How many crisps do you want? ");
    wscanf(L"%d", &quantity); // 2
    total = quantity * 1.4; // 3
    wprintf(L"That will be %lc%.2f\n", pound, total); // 4

    return 0;
}

// 1. The pound character is defined as a wchar_t constant
// 2. Just like a scanf() statement, but with a wide character formattin string
// 3. Random math, just to have the code do something
// 4. The %lc placeholder outputs the pound symbol; %.2f formats the amount to
// two decimal places