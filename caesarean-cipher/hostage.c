#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ch, r;

    srand( (unsigned) time(NULL) );

    while ( (ch = getchar()) != EOF ) {
        r = rand() % 2;

        if ( r )
            putchar(toupper(ch));
        else
            putchar(tolower(ch));
    }

    return 0;
}

// I/O redirection is a powerful feature of the shell. It allows you to connect
// the standard input and output of a program to files or other programs.
//    _____________________________________________________________________
//   |                                                                     |
//   | > redirects standard output to a file (not really used for filters) |
//   | < redirects standard input from a file                              |
//   | | sends output through another program                              |
//   |_____________________________________________________________________|

// This code should be compiled into a ransom.exe program. Example commands:
// echo "Give me all your money" | ./ransom (pipe)
// ./ransom < file.txt (input redirection)
// echo "Give me all your money" | ./ransom > ranson-note.txt (output redirection)

// !! output redirection doesn't supply input for a filter. Use the pipe to send
// output from one program into the filter.