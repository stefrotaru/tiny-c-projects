#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char uppercase(void) {
    return ( rand() % 26 + 'A' );
}

char lowercase(void) {
    char ch;

    ch = uppercase();
    return ( ch |= 0x20 );
}

char number(void) {
    return ( rand() % 10 + '0' );
}

char symbol(void) {
    char s[10] = "!@#$%*^_-";
    int r;

    r = rand() % 8;
    return s[r];
}

void scramble(char p[]) {
    const int size = UPPER+LOWER+NUM+SYM; // 1
    char key[size];
    int x, r;

    for ( x=0; x<size; x++ ) // 2
        key[x] = '\0';
    
    x = 0; // 3
    while ( x<size - 1 ) { // 4
        r = rand() % (size - 1); // 5
        if ( !key[r] ) { // 6
            key[r] = p[x]; // 7
            x++; // 8
        }
    }

    for( x=0; x<size; x++ ) // 9
        p[x] = key[x];
}

int main() {
    char password[ UPPER+LOWER+NUM+SYM+1 ];
    int x;

    srand( time(NULL) );

    x = 0;
    while ( x<UPPER )
        password[x++] = uppercase();
    while ( x<UPPER+LOWER )
        password[x++] = lowercase();
    while ( x<UPPER+LOWER+NUM )
        password[x++] = number();
    while ( x<UPPER+LOWER+NUM+SYM )
        password[x++] = symbol();
    password[x] = '\0';

    scramble(password);

    printf("Generated random password: %s\n", password);

    return 0;
}

// 1. Calculates the buffer size
// 2. Initializes the array with null characters
// 3. The index into the passed array
// 4. Loops until the passed array has been fully processed (minus one for
// the null character)
// 5. Generates a random value, 0 through the buffer size (minus one for 
// the null character)
// 6. If the random value at element r is a null character...
// 7. ...it copies the oriinal character to its new, random position.
// 8. Updates the index
// 9. Copies the randomized array into the passed array