#include <stdio.h>

int main() {
    int ch;

    while ( (ch = getchar()) != EOF ) {
        printf("%02X ", ch); // 1
    }

    return 0;
}

// 1. %02X outputs character as two-digit hex byte, with a leading 0 