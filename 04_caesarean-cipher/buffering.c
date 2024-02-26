#include <stdio.h>

int main() {
    char buffer[BUFSIZ]; // 1
    int a, b;

    setbuf(stdout, buffer); // 2

    printf("Type a letter: ");
    a = getchar();
    printf("Type a letter: ");
    b = getchar();

    printf("a='%c', b='%c'\n", a, b);

    return(0);
}

// 1. A holding bin for standard output; BUFSIZ is defined in stdio.h
// 2. Commits standard output to block buffering

// If you build and run buffering.c, you see no output. Instead, the getchar() function
// prompts for input, so the program waits. The output is held back, stored in the char
// array buffer, waiting for text to fill the buffer or for the program to end.