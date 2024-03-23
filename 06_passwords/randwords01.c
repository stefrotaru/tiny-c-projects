#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define repeat(a) for(int x=0; x<a; x++) // 1

const char *add_word(void) {
    const char *vocabulary[] = {
        "orange", "grape", "apple", "banana",
		"coffee", "tea", "juice", "beverage",
		"happy", "grumpy", "bashful", "sleepy" 
    };
    int r;

    r = rand() % ( sizeof(vocabulary) / sizeof(char *) ); // 2
    return ( vocabulary[r] ); // 3
}

int main() {
    srand( time(NULL) );

    repeat(3) // 4
        printf("%s ", add_word());
    putchar('\n');

    return 0;

}

// 1. This amcro makes the for loop more readable in the main() function
// 2. Generates a random value, zero through the number of elements in the array
// (minus one)
// 3. Returns the random element - the word
// 4. Outputs three random words