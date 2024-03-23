#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x;
    char ch;
    const int length = 10; // 1

    srand( time(NULL) );
    
    for( x = 0; x < length; x++ ) {
        ch = rand() % ('-' - '!' + 1); // 2
        putchar( ch + '!' ); // 3
    }
    putchar('\n');

    return 0;
}

// 1. Makes the password 10 characters long
// 2. Sets the range of random values to printable characters
// 3. Outputs the printable character