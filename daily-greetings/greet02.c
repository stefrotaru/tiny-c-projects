#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hello, you handsome beast!");
    } else {
        printf("Hello, %s!", argv[1]);
    }

    return 0;
}

// argc is the number of arguments
// argv[1] is the first argument
// argv[0] is the name of the program