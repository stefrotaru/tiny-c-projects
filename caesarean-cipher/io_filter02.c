#include <stdio.h>

int main() {
    int ch;

    while ( (ch = getchar()) != EOF ) {
        switch(ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                putchar('*');
                break;
            default:
                putchar(ch);
        }
    }

    return 0;
}

// This program modifies the input stream, replacing all vowels with asterisks. It's a simple filter.