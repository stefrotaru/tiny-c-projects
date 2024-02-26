#include <stdio.h>

int flip(char *c, int pos) {
    *(c+pos) = *(c+pos) + 1; // 1
    if ( *(c+pos) > 'z' ) { // 2
        *(c+pos) = 'a'; // 3
        if ( pos != 0 ) { // 4
            if ( !flip(c, pos-1) ) // 5
                return 0;
        } else {
            return 0; // 6
        }
    }
    return 1; // 7
}

int main() {
    char password[] = "password"; // 8
    char guess[] = "aaaaaaa"; // 9
    char *p, *g; // 10

    printf("Password is cracking...\n");

    do {
        p = password; // 11
        g = guess; // 11
        while ( *p ) { // 12
            if ( *p == *g ) { // 13
                p++;
                g++;
            } 
            else 
                break; // 14
        }

        if ( *p == '\0' && *g == '\0' ) { // 15
            printf("Found password '%s'\n", guess);
            break; // 16
        }
    }

    while ( flip(guess, 7) ); // 17

    return 0;
}

// This function rolls over the 'digits' in the array from 'a' to 'z'. When 'z' is
// encountered, the column shift back to 'a', but the function is recursively called
// to the next position left, which is -1 element in the array. A check is made to
// ensure that the function doesn't attempt to modify array elements < 0. Argumnt
// 'c' is the char array. Argument pos is the element position, highest first

// 1. Increment the character at the position
// 2. Check for overflow
// 3. Set the character to 'a'
// 4. Watch for overflow
// 5. Call the function recursively
// 6. Last column, FALSE return
// 7. Keep looping

// 8. The password to crack
// 9. Initialised to make it easier
// 10. Pointers to the arrays
// 11. Set the pointers
// 12. Loop through the password
// 13. Compare each letter
// 14. Break when they don't match
// 15. If both characters are null here, the strings match
// 16. Print the password and stop the loop

// 17. Keep looping until the password is found