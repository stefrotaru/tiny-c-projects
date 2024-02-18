#include <stdio.h>

int main() {
    int a, b;

    printf("Type a letter: ");
    a = getchar(); // 1
    printf("Type a letter: ");
    b = getchar(); // 2

    printf("a='%c' b='%c' \n", a, b);

    return 0;
}

// 1. Reads a single character from standard input
// 2. Reads the next single character from standard input