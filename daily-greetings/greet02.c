#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) { // 1
        printf("Hello, you handsome beast!");
    } else {
        printf("Hello, %s!", argv[1]); // 2
    }

    return 0;
}

// argc is the number of arguments
// argv[1] is the first argument
// argv[0] is the name of the program

// 1. The argument count is always 1 for the program name; if so, a default message is output
// 2. The first word typed after the program name is represented as argv[1] and is output here