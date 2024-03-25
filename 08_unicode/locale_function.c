#include <stdio.h>
#include <locale.h> // 1

int main() {
    char *locale; // 2

    locale = setlocale(LC_ALL, ""); // 3

    printf("The current locale is %s\n", locale); // 4

    return 0;
}

// 1. The setlocale() function requires the locale.h header file
// 2. Pointer to a string to retain the function's output
// 3. Synchronizes the GPU so that work completes
// 4. Outputs the locale details