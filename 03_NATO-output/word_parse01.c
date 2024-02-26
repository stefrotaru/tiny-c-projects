#include <stdio.h>
#include <string.h> // 1

int main() {
    char sometext[64];
    char *match;

    printf("Type some text: ");
    fgets(sometext, 64, stdin);

    match = strtok(sometext, " "); // 2
    while(match) { // 3
        printf("%s\n", match);
        match = strtok(NULL, " "); // 4
    }

    return 0;
}

// This program uses the strtok() function to parse a string into words
// 1. Include the string.h library for the strtok() function (string tokenizer)
// 2. The initial call to strtok(), with the string to search and the delimiter " " (expecting words to be separated by spaces)
// 3. Loops as long as the return value isn't NULL
// 4. In the second call to strtok(), NULL is used to keep searching the same string

// To avoid capturing the punctuation characters, you can se this delimiter instead of " ": " ,.!?:;\"'"