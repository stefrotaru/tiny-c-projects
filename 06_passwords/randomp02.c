#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char uppercase(void) {
    return ( rand() % 26 + 'A' ); // 1
}

char lowercase(void) {
    char ch;

    ch = uppercase();
    return ( ch |= 0x20 ); // 2
}

char number(void) {
    return ( rand() % 10 + '0' ); // 3
}

char symbol(void) {
    char s[10] = "!@#$%*^_-"; // 4
    int r;

    r = rand() % 8;
    return s[r]; // 5
}

int main() {
    int x;
    
    srand( time(NULL) ); // 6

    // 7
    for ( x=0; x<UPPER; x++ )
        putchar( uppercase() );
    for ( x=0; x<LOWER; x++ )
        putchar( lowercase() );
    for ( x=0; x<NUM; x++ ) 
        putchar( number() );
    for ( x=0; x<SYM; x++ )
        putchar( symbol() );
    putchar('\n');

    return 0;
}

// 1. Pick a random number between 0 and 25, turn it into an uppercase letter by adding the ASCII value of 'A'
// 2. Convert the uppercase letter to lowercase
// 3. Pick a random number between 0 and 9, turn it into a number by adding the ASCII value of '0'
// 4. Safe symbols
// 5. Return a random symbol from the array of safe symbols
// 6. Seed the random number generator. By passing time(NULL) as the argument, the seed is set to the current time, which is always changing
// 7. Generate the password by calling the functions for uppercase, lowercase, number, and symbol the appropriate number of times