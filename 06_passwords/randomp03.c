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

int main() {
    char password[ UPPER+LOWER+NUM+SYM+1 ]; // 1
    int x;

    srand( time(NULL) ); // 2

    x = 0; // 3
    while ( x<UPPER ) // 4
        password[x++] = uppercase();
    while ( x<UPPER+LOWER ) // 5
        password[x++] = lowercase();
    while ( x<UPPER+LOWER+NUM ) // 6
        password[x++] = number();
    while ( x<UPPER+LOWER+NUM+SYM ) // 7
        password[x++] = symbol();
    password[x] = '\0'; // 8

    printf("Generated random password: %s\n", password); // 9

    return 0;
}

// 1. Necessary storage for the password, plus one for the null character
// 2. Seeds the randomizer
// 3. Initializes the index variable "x"
// 4. Fetches the uppercase letters and puts them in teh passowrd[] array
// 5. Fetches the lowercase letters
// 6. Fetches the numbers
// 7. Fetches the symbols
// 8. Caps the string with a null character
// 9. Outputs the password

// Difference between randomp02.c and this version is that the this version
// stores the password in a buffer and can pass it into a new function,
// scramble(), to shuffle the characters around.